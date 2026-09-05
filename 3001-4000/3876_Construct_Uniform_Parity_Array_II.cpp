/*
Problem Number: 3876
Problem Name: Construct Uniform Parity Array II

LeetCode Link:
https://leetcode.com/problems/construct-uniform-parity-array-ii/

Difficulty: Medium

Topics:
Array, Math, Parity

Approach:
We need to determine whether we can construct nums2 such that
all its elements are either odd or all even.

The important restriction is that when subtracting another
element, the result must be positive.

Steps:

1. Find the minimum element of nums1.

2. If the minimum element is odd, return true.

   The minimum element can be used as the subtracted value
   for larger even elements.

   For an even element x:

       x - odd = odd

   So all required elements can be made odd.

3. If the minimum element is even, we cannot use a smaller
   odd element to change an even number into an odd number.

4. Therefore, when the minimum element is even, every element
   must already be even.

5. Check every element:
   - If an odd element exists, return false.
   - Otherwise, all elements are even, so we can keep every
     element unchanged.

6. Therefore:
   - Minimum is odd -> possible.
   - Minimum is even and all elements are even -> possible.
   - Minimum is even and any element is odd -> impossible.

Time Complexity:
O(n)

Space Complexity:
O(1)

where:
n = length of nums1
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // If minimum is odd, we can make all elements odd
        if (mn % 2 == 1)
            return true;

        // Minimum is even.
        // Then every element must be even.
        for (int x : nums1) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};
