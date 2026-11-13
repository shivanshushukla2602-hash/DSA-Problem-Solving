# Binary Search

- **Platform:** LeetCode
- **Link:** https://leetcode.com/problems/binary-search/
- **Difficulty:** Easy
- **Tags:** array, binary-search
- **Language:** C++
- **Solved on:** 2026-05-20

## Problem summary

Find the index of a target value within a sorted array.

## Approach

Maintain low and high pointers, calculate mid, and halve the search interval based on comparison with the target.

## Complexity

- **Time:** O(log n) logarithmic time search.
- **Space:** O(1) constant auxiliary space.

## Edge cases

Target not present, array of length 1, target at boundary (first or last element).
