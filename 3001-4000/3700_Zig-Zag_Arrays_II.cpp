/*
Problem Number: 3700
Problem Name: Zig-Zag Arrays II

LeetCode Link:
https://leetcode.com/problems/zig-zag-arrays-ii/

Difficulty: Hard

Topics:
Dynamic Programming, Matrix Exponentiation,
Math, State Compression

Approach:
The constraints are much larger than
Zig-Zag Arrays I, so O(n × m) DP is not enough.

Observation:

A Zig-Zag sequence alternates between:

a1 < a2 > a3 < a4 ...

or

a1 > a2 < a3 > a4 ...

We define states:

D[x]
= sequences ending at value x
  where next value must be greater

U[x]
= sequences ending at value x
  where next value must be smaller

Transition:

D[x] → U[y]
for y > x

U[x] → D[y]
for y < x

These transitions form a fixed
transition matrix T.

Since:

DP(n) = T × DP(n-1)

we get:

DP(n) = T^(n-2) × DP(2)

Use Matrix Exponentiation to compute:

T^(n-2)

in O(log n).

Time Complexity:
O((2m)^3 log n)

Space Complexity:
O((2m)^2)

where:

m = r - l + 1
*/
