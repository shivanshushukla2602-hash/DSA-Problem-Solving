#!/usr/bin/env python3
"""Move N unique, not-yet-pushed problems from .dsa-sync/backlog.json into the repo.

One commit per problem. Never repeats the same platform+ID (checked against state.json and the repo
folders). The same problem on two platforms is pushed once per platform. Does not push;
the workflow does `git push` afterwards.
"""
import json
import os
import re
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SYNC = ROOT / ".dsa-sync"
BACKLOG, STATE, README = SYNC / "backlog.json", SYNC / "state.json", ROOT / "README.md"
PER_RUN = int(os.environ.get("PER_RUN", "2"))
FORCE = os.environ.get("FORCE", "").lower() in ("1", "true", "yes")
START, END = "<!-- DSA-INDEX-START -->", "<!-- DSA-INDEX-END -->"
SKIP_DIRS = {".git", ".github", ".dsa-sync", "scripts"}
NOT_ADDED = "_Not added yet._"


def slugify(s):
    return re.sub(r"[^a-z0-9]+", "-", s.lower()).strip("-")


def norm(s):
    return re.sub(r"[^a-z0-9]", "", s.lower())


def key(p):
    return f"{p['platform'].lower()}:{p['id']}"


def load_json(path, default):
    return json.loads(path.read_text(encoding="utf-8")) if path.exists() else default


def git(*args):
    subprocess.run(["git", *args], cwd=ROOT, check=True)


def repo_existing():
    """Platform:ID keys of problems already in the repo folders."""
    keys = set()
    for sol in ROOT.glob("*/*/*/solution.*"):
        rel = sol.relative_to(ROOT).parts
        if rel[0] in SKIP_DIRS:
            continue
        pid, _, _ = sol.parent.name.partition("-")
        keys.add(f"{rel[0].lower()}:{pid}")
    return keys


def pick(backlog, done_keys, n):
    seen, pool = set(done_keys), []
    for p in backlog:
        if key(p) in seen:
            continue
        seen.add(key(p))  # drop exact duplicates (same platform + ID)
        pool.append(p)
    chosen = []
    while pool and len(chosen) < n:
        used_plat = {c["platform"] for c in chosen}
        used_title = {norm(c["title"]) for c in chosen}
        # Prefer a different title AND platform in the same batch, then a different title, then anything.
        nxt = (
            next((p for p in pool if norm(p["title"]) not in used_title and p["platform"] not in used_plat), None)
            or next((p for p in pool if norm(p["title"]) not in used_title), None)
            or pool[0]
        )
        chosen.append(nxt)
        pool.remove(nxt)
    return chosen, len(pool)


def write_problem(p):
    diff = p.get("difficulty", "Unknown").title()
    folder = ROOT / p["platform"] / diff / f"{p['id']}-{slugify(p['title'])}"
    if folder.exists():
        sys.exit(f"Refusing to overwrite existing folder: {folder}")
    folder.mkdir(parents=True)
    (folder / f"solution.{p.get('ext') or 'txt'}").write_text(
        p["code"].rstrip() + "\n", encoding="utf-8"
    )
    tags = ", ".join(p.get("tags", [])) or "-"
    lines = [
        f"# {p['title']}", "",
        f"- **Platform:** {p['platform']}",
        f"- **Link:** {p['url']}",
        f"- **Difficulty:** {diff}",
        f"- **Tags:** {tags}",
        f"- **Language:** {p.get('language', '-')}",
        f"- **Solved on:** {p.get('solved_date', '-')}", "",
    ]
    for heading, field in [("Problem summary", "summary"), ("Approach", "approach")]:
        lines += [f"## {heading}", "", p.get(field) or NOT_ADDED, ""]
    lines += [
        "## Complexity", "",
        f"- **Time:** {p.get('time') or NOT_ADDED}",
        f"- **Space:** {p.get('space') or NOT_ADDED}", "",
        "## Edge cases", "", p.get("edge_cases") or NOT_ADDED, "",
    ]
    (folder / "README.md").write_text("\n".join(lines), encoding="utf-8")
    return folder, diff


def add_index_row(p, diff, folder, today):
    text = README.read_text(encoding="utf-8") if README.exists() else "# DSA Problem Solving\n"
    if START not in text or END not in text:
        text = (
            text.rstrip()
            + f"\n\n## Solved problems\n\n{START}\n"
            "| Date | Platform | Problem | Difficulty |\n|---|---|---|---|\n"
            f"{END}\n"
        )
    rel = folder.relative_to(ROOT).as_posix()
    row = f"| {today} | {p['platform']} | [{p['id']}. {p['title']}]({rel}) | {diff} |\n"
    README.write_text(text.replace(END, row + END), encoding="utf-8")


def main():
    backlog = load_json(BACKLOG, None)
    if backlog is None:
        sys.exit(f"Missing {BACKLOG}. Build the backlog first.")
    state = load_json(STATE, {"pushed": []})
    today = datetime.now(timezone.utc).strftime("%Y-%m-%d")

    pushed_today = sum(1 for e in state["pushed"] if e.get("date") == today)
    if pushed_today >= PER_RUN and not FORCE:
        print(f"Already pushed {pushed_today} today. Skipping (set FORCE=1 to override).")
        return
    n = PER_RUN if FORCE else PER_RUN - pushed_today

    done_keys = {e["key"] for e in state["pushed"]} | repo_existing()

    chosen, remaining = pick(backlog, done_keys, n)
    if not chosen:
        print("Backlog is empty. Re-scan the platforms for newly solved problems.")
    for p in chosen:
        folder, diff = write_problem(p)
        add_index_row(p, diff, folder, today)
        state["pushed"].append({"key": key(p), "title": p["title"], "date": today})
        STATE.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")
        git("add", folder.relative_to(ROOT).as_posix(), "README.md", ".dsa-sync/state.json")
        git("commit", "-m", f"Add: {p['platform']} {p['id']} - {p['title']} ({diff})")
        print(f"Committed {p['platform']} {p['id']} - {p['title']}")

    msg = f"Pushed {len(chosen)} problem(s). {remaining} problem(s) left in backlog."
    print(msg)
    if remaining < 7 and os.environ.get("GITHUB_STEP_SUMMARY"):
        with open(os.environ["GITHUB_STEP_SUMMARY"], "a") as f:
            f.write(f"**{msg}** Backlog is running low; re-scan the platforms.\n")


if __name__ == "__main__":
    main()
