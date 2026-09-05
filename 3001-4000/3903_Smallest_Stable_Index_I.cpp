/*
Problem Number: 3903
Problem Name: Smallest Stable Index I

LeetCode Link:
https://leetcode.com/problems/smallest-stable-index-i/

Difficulty: Easy

Topics:
Array, Prefix Maximum, Suffix Minimum

Approach:
We need to find the smallest index i whose instability
score is at most k.

The instability score of index i is:

max(nums[0...i]) - min(nums[i...n-1])

Steps:

1. Build a suffix minimum array.

   suffixMin[i] stores the minimum element from index i
   to the end of the array.

2. Traverse the array from left to right while maintaining
   the maximum value seen so far.

3. For every index i:

   prefixMax = maximum value from nums[0...i]

   suffixMin[i] = minimum value from nums[i...n-1]

4. Calculate the instability score:

   prefixMax - suffixMin[i]

5. If the instability score is less than or equal to k,
   then i is stable.

6. Since we traverse from left to right, the first stable
   index is the smallest stable index.

7. If no index satisfies the condition, return -1.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = length of nums
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        // Suffix minimum
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int prefixMax = nums[0];

        // Find the smallest stable index
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
