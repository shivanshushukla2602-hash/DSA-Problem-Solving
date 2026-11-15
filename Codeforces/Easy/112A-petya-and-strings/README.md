# Petya and Strings

- **Platform:** Codeforces
- **Link:** https://codeforces.com/contest/112/problem/A
- **Difficulty:** Easy
- **Tags:** implementation, strings
- **Language:** GNU C11
- **Solved on:** 2026-03-20

## Problem summary

Compare two strings lexicographically in a case-insensitive manner.

## Approach

Convert characters of both strings to lowercase and compare character by character, returning -1, 1, or 0.

## Complexity

- **Time:** O(n) where n is the length of the strings.
- **Space:** O(1) auxiliary space modifying strings in place.

## Edge cases

Identical strings with different casing.
