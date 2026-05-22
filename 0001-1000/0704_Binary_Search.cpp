/*
Problem Number: 0704
Problem Name: Binary Search

Difficulty: Easy

Topics:
Array, Binary Search

Approach:
Use Binary Search on the sorted array.

Compare target with middle element:
- If equal → return index
- If target is greater → search right half
- Otherwise → search left half

Time Complexity:
O(log n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Target found
            if(nums[mid] == target) {
                return mid;
            }

            // Search right half
            if(nums[mid] < target) {
                left = mid + 1;
            }

            // Search left half
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
