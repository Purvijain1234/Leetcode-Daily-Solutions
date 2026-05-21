/*
Problem Number: 0027
Problem Name: Remove Element

Difficulty: Easy

Topics:
Array, Two Pointers

Approach:
Use two pointers.

Traverse the array and copy only
those elements which are not equal
to val.

k stores the position for valid elements.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int removeElement(vector<int>& nums, int val) {

        // Pointer for valid elements
        int k = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Keep elements not equal to val
            if(nums[i] != val) {

                nums[k] = nums[i];

                k++;
            }
        }

        return k;
    }
};
