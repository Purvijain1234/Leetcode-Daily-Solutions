/*
Problem Number: 3658
Problem Name: GCD of Odd and Even Sums

LeetCode Link:
https://leetcode.com/problems/gcd-of-odd-and-even-sums/

Difficulty: Easy

Topics:
Math, Number Theory

Approach:
The first n odd numbers are:

1, 3, 5, ..., (2n-1)

Their sum is:

n²

The first n even numbers are:

2, 4, 6, ..., 2n

Their sum is:

n(n + 1)

Now compute:

gcd(n², n(n + 1))

Factor out n:

gcd(n², n(n + 1))
= n × gcd(n, n + 1)

Since consecutive integers are always
coprime:

gcd(n, n + 1) = 1

Therefore:

gcd = n

So the answer is simply n.

Time Complexity:
O(1)

Space Complexity:
O(1)
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
