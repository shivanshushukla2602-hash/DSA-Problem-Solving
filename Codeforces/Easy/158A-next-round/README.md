# Next Round

- **Platform:** Codeforces
- **Link:** https://codeforces.com/contest/158/problem/A
- **Difficulty:** Easy
- **Tags:** *special, implementation
- **Language:** GNU C11
- **Solved on:** 2026-03-16

## Problem summary

Count how many participants advance to the next round by scoring at least as many points as the k-th place finisher and having a positive score.

## Approach

Find the k-th participant's score, then iterate through the scores and count participants whose score is >= k-th score and > 0.

## Complexity

- **Time:** O(n) where n is the number of participants.
- **Space:** O(n) or O(1) space to store or stream scores.

## Edge cases

k-th place finisher has a score of 0 (no one with 0 points can advance).
