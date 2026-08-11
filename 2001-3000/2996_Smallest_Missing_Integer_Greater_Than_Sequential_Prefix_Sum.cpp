/*
Problem Number: 2996
Problem Name: Smallest Missing Integer Greater Than Sequential Prefix Sum

LeetCode Link:
https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

Difficulty: Easy

Topics:
Array, Hash Table

Approach:
We need to find the sum of the longest sequential prefix
of nums and then find the smallest integer greater than or
equal to this sum that does not exist in nums.

Steps:

1. Start with the first element of nums as the initial sum.

2. Traverse the array from the second element.

3. Continue adding elements to the sum as long as the
   current element is exactly one greater than the previous
   element.

   For example:
   [3, 4, 5, 1, 2]

   The longest sequential prefix is:
   [3, 4, 5]

   Its sum is:
   3 + 4 + 5 = 12

4. Once the sequential prefix ends, stop calculating the sum.

5. Store all elements of nums in an unordered_set so that
   we can quickly check whether an integer exists.

6. Starting from the calculated sum, keep increasing it while
   it exists in the set.

7. The first integer that does not exist in nums is the answer.

Example:

nums = [1, 2, 3, 2, 5]

Sequential prefix:
1 + 2 + 3 = 6

If 6 is not present in nums, the answer is 6.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = number of elements in nums
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Find the sum of the longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find the smallest missing integer >= sum
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(sum)) {
            sum++;
        }

        return sum;
    }
};
