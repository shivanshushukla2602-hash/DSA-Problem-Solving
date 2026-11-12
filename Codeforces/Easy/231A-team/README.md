# Team

- **Platform:** Codeforces
- **Link:** https://codeforces.com/contest/231/problem/A
- **Difficulty:** Easy
- **Tags:** brute force, greedy
- **Language:** GNU C11
- **Solved on:** 2026-03-11

## Problem summary

Count how many problems will be implemented if at least two out of three team members are sure about the solution.

## Approach

Iterate through each problem, sum the three opinions, and increment the counter if the sum is 2 or greater.

## Complexity

- **Time:** O(n) where n is the number of problems.
- **Space:** O(1) auxiliary space.

## Edge cases

All 0s (sum = 0) or all 1s (sum = 3).
