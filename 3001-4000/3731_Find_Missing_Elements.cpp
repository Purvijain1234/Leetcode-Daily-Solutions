/*
Problem Number: 3731
Problem Name: Find Missing Elements

LeetCode Link:
https://leetcode.com/problems/find-missing-elements/

Difficulty: Easy

Topics:
Array, Sorting

Approach:
The array is sorted first so that all
numbers appear in increasing order.

Then:

1. Traverse every pair of adjacent
   elements.

2. If there is a gap between two
   consecutive numbers, every number
   inside that gap is missing.

3. Add all missing numbers to the
   answer.

4. Return the list of missing elements.

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(Excluding the output array)
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n-1; i++){
            for(int x = nums[i]+1; x<nums[i+1]; x++){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
