/*
Problem Number: 3904
Problem Name: Smallest Stable Index II

LeetCode Link:
https://leetcode.com/problems/smallest-stable-index-ii/

Difficulty: Medium

Topics:
Array, Prefix Maximum, Suffix Minimum

Approach:
We need to find the smallest index i whose instability
score is less than or equal to k.

The instability score of index i is:

max(nums[0...i]) - min(nums[i...n-1])

Steps:

1. Build a suffix minimum array.

   suffixMin[i] stores the minimum element from index i
   to the end of the array.

2. Traverse nums from left to right.

3. Maintain prefixMax, which stores the maximum element
   from index 0 to the current index i.

4. For every index i, calculate:

   prefixMax - suffixMin[i]

5. If this value is less than or equal to k, then i is
   a stable index.

6. Since we check indices from left to right, the first
   stable index is the smallest stable index.

7. If no stable index exists, return -1.

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

        // suffixMin[i] = minimum element from i to n-1
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // prefixMax = maximum element from 0 to i
        int prefixMax = 0;

        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, nums[i]);

            // instability score
            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};

