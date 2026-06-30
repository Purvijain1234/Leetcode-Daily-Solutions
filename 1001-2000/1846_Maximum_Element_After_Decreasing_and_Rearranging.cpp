/*
Problem Number: 1846
Problem Name: Maximum Element After Decreasing and Rearranging

LeetCode Link:
https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

Difficulty: Medium

Topics:
Array, Greedy, Sorting

Approach:
To maximize the largest element while satisfying:

1. The first element must be 1.
2. The absolute difference between adjacent
   elements must be at most 1.

Steps:
1. Sort the array.
2. Set the first element to 1.
3. Traverse the array:
   - Each element can be at most
     previous element + 1.
   - Replace:
       arr[i] = min(arr[i], arr[i-1] + 1)
4. The last element becomes the
   maximum possible value.

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(excluding sorting space)
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};
