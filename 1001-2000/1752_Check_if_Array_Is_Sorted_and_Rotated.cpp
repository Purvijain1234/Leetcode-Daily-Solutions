/*
Problem Number: 1752
Problem Name: Check if Array Is Sorted and Rotated

Difficulty: Easy

Topics:
Array

Approach:
Traverse the array and count the number
of places where current element is greater
than the next element.

For a sorted and rotated array,
this count should be at most 1.

Modulo (%) is used to compare the last
element with the first element.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // Compare current element with next element
            if(nums[i] > nums[(i + 1) % n]) {

                count++;
            }
        }

        return count <= 1;
    }
};
