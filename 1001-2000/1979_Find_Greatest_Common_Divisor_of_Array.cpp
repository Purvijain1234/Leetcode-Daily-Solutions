/*
Problem Number: 1979
Problem Name: Find Greatest Common Divisor of Array

LeetCode Link:
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

Difficulty: Easy

Topics:
Array, Math, Number Theory

Approach:
The GCD of the entire array is determined
by the smallest and largest elements.

Steps:

1. Find the minimum element in the array.
2. Find the maximum element in the array.
3. Compute the GCD of these two values
   using the Euclidean Algorithm.
4. Return the result.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        return __gcd(min, max);
    }
};
