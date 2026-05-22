/*
Problem Number: 0033
Problem Name: Search in Rotated Sorted Array

Difficulty: Medium

Topics:
Array, Binary Search

Approach:
Use Binary Search to determine which half
of the array is sorted.

If the left half is sorted:
check whether target lies in that range.

Otherwise:
search in the right half.

Similarly,
if right half is sorted,
check target range accordingly.

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

            // Left half is sorted
            if(nums[left] <= nums[mid]) {

                // Target lies in left half
                if(target >= nums[left] &&
                   target < nums[mid]) {

                    right = mid - 1;
                }

                else {

                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in right half
                if(target > nums[mid] &&
                   target <= nums[right]) {

                    left = mid + 1;
                }

                else {

                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
