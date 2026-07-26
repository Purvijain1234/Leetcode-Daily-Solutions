/*
Problem Number: 628
Problem Name: Maximum Product of Three Numbers

LeetCode Link:
https://leetcode.com/problems/maximum-product-of-three-numbers/

Difficulty: Easy

Topics:
Array, Math, Greedy

Approach:
The maximum product of three numbers can
come from two possible cases:

1. The three largest numbers.
2. The two smallest (most negative)
   numbers and the largest number.

Steps:

1. Traverse the array once.
2. Maintain:
      max1 = largest
      max2 = second largest
      max3 = third largest
3. Also maintain:
      min1 = smallest
      min2 = second smallest
4. Compute:
      max1 × max2 × max3
5. Compute:
      min1 × min2 × max1
6. Return the larger of the two products.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums) {
            // Update largest three
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }

            // Update smallest two
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};
