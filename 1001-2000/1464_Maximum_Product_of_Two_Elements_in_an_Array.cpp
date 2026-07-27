/*
Problem Number: 1464
Problem Name: Maximum Product of Two Elements in an Array

LeetCode Link:
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

Difficulty: Easy

Topics:
Array, Greedy

Approach:
We need to maximize:

    (a - 1) × (b - 1)

where a and b are two different elements
from the array.

Steps:

1. Traverse the array once.
2. Maintain:
      max1 = largest element
      max2 = second largest element
3. If the current element is larger than
   max1, update both max1 and max2.
4. Otherwise, if it is larger than max2,
   update max2.
5. Return:
      (max1 - 1) × (max2 - 1)

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = 0;
        int max2 = 0;
        for(int num : nums){
            if(num > max1){
                max2 = max1;
                max1 = num;
            }
            else if(num > max2){
                max2 = num;
            }
        }
        return (max1-1)*(max2-1);
    }
};
