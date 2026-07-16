/*
Problem Number: 3867
Problem Name: GCD Sum of Prefix Maximums

LeetCode Link:
https://leetcode.com/problems/gcd-sum-of-prefix-maximums/

Difficulty: Medium

Topics:
Array, Math, Number Theory, Sorting

Approach:
For every index:

1. Maintain the maximum element seen so far.
2. Compute:
      prefixGcd[i] = gcd(nums[i], prefixMaximum)
3. Store all prefix GCD values.
4. Sort the prefix GCD array.
5. Pair the smallest and largest values,
   second smallest and second largest, etc.
6. Add the GCD of every pair to obtain
   the final answer.

Time Complexity:
O(n log n)

Space Complexity:
O(n)
*/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
