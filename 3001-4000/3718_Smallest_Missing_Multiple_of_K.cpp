/*
Problem Number: 3718
Problem Name: Smallest Missing Multiple of K

LeetCode Link:
https://leetcode.com/problems/smallest-missing-multiple-of-k/

Difficulty: Easy

Topics:
Array, Hash Table, Math

Approach:
We need to find the smallest positive multiple of k
that does not appear in nums.

Steps:

1. Store all elements of nums in an unordered_set for
   O(1) average-time lookup.

2. Start with x = k, the smallest positive multiple of k.

3. Check whether x exists in the set.

4. If x exists, move to the next multiple:

       x += k

5. Continue until a multiple of k is not present in nums.

6. Return that missing multiple.

Example:

nums = [2,3,4,6,8,10]
k = 2

Multiples of 2:

2 → present
4 → present
6 → present
8 → present
10 → present
12 → missing

Answer = 12

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = number of elements in nums
*/
