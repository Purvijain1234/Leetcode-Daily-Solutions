/*
Problem Number: 0026
Problem Name: Remove Duplicates from Sorted Array

Difficulty: Easy

Topics:
Array, Two Pointers

Approach:
Use two pointers.

One pointer traverses the array,
and another pointer keeps track
of unique elements.

When a new unique element is found,
place it at index k.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        // Pointer for unique elements
        int k = 1;
        for(int i = 1; i < nums.size(); i++) {
            // New unique element found
            if(nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
