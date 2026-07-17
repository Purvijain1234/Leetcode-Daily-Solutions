/*
Problem Number: 3312
Problem Name: Sorted GCD Pair Queries

LeetCode Link:
https://leetcode.com/problems/sorted-gcd-pair-queries/

Difficulty: Hard

Topics:
Math, Number Theory, Prefix Sum,
Binary Search, Inclusion-Exclusion,
Counting

Approach:
We need to answer queries on the sorted
array of GCD values of all pairs without
explicitly generating O(n²) pairs.

Steps:

1. Count the frequency of every value.

2. For every divisor d, compute:
      cntDiv[d]
   = number of array elements divisible
     by d.

3. Calculate the number of pairs whose
   GCD is exactly d using the
   Inclusion-Exclusion Principle:

      pairs =
      C(cntDiv[d], 2)

   Subtract all pairs already counted
   for multiples of d.

4. Build a prefix sum array where:

      pref[d]

   stores the total number of pairs with
   GCD ≤ d.

5. For each query k:
   Use Binary Search on pref[] to find
   the smallest GCD whose cumulative
   pair count exceeds k.

Time Complexity:
O(M log M + Q log M)

where:
M = maximum value in nums
Q = number of queries

Space Complexity:
O(M)
*/

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cntDiv[d] = how many numbers are divisible by d
        vector<int> cntDiv(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cntDiv[d] += freq[m];
        }

        // exactPairs[d] = number of pairs whose gcd is exactly d
        vector<long long> exactPairs(mx + 1, 0);
        for (int d = mx; d >= 1; d--) {
            long long c = cntDiv[d];
            long long pairs = c * (c - 1) / 2;
            for (int m = d + d; m <= mx; m += d)
                pairs -= exactPairs[m];
            exactPairs[d] = pairs;
        }

        // prefix counts over gcd values
        vector<long long> pref(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            pref[d] = pref[d - 1] + exactPairs[d];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
