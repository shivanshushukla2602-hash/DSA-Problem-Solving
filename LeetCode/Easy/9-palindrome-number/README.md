# Palindrome Number

- **Platform:** LeetCode
- **Link:** https://leetcode.com/problems/palindrome-number/
- **Difficulty:** Easy
- **Tags:** math
- **Language:** C
- **Solved on:** 2026-02-27

## Problem summary

Determine whether an integer reads the same forwards and backwards.

## Approach

Negative numbers cannot be palindromes. For non-negative integers, reverse the digits iteratively and compare the reversed value with the original number.

## Complexity

- **Time:** O(log10(n)) proportional to the number of decimal digits.
- **Space:** O(1) auxiliary space using scalar variables.

## Edge cases

Negative numbers return false; numbers ending in 0 (other than 0 itself) cannot be palindromes.
