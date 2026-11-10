# Watermelon

- **Platform:** Codeforces
- **Link:** https://codeforces.com/contest/4/problem/A
- **Difficulty:** Easy
- **Tags:** brute force, math
- **Language:** GNU C11
- **Solved on:** 2026-01-14

## Problem summary

Determine if a watermelon of weight w can be divided into two parts, each weighing an even positive integer amount.

## Approach

Check if the weight is strictly greater than 2 and divisible by 2. Any even number greater than 2 can be split into two even positive integers (e.g., 2 and w - 2).

## Complexity

- **Time:** O(1) constant time parity check.
- **Space:** O(1) constant auxiliary space.

## Edge cases

w = 2 is even but cannot be split into two positive even integers.
