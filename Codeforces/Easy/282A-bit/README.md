# Bit++

- **Platform:** Codeforces
- **Link:** https://codeforces.com/contest/282/problem/A
- **Difficulty:** Easy
- **Tags:** implementation
- **Language:** GNU C11
- **Solved on:** 2026-03-13

## Problem summary

Calculate the final value of variable X starting at 0 after executing a sequence of increment and decrement statements.

## Approach

For each statement, check if it contains '+' to increment X, otherwise decrement X.

## Complexity

- **Time:** O(n) where n is the number of statements.
- **Space:** O(1) auxiliary space.

## Edge cases

Initial state X = 0.
