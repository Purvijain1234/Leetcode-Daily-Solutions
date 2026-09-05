/*
Problem Number: 3875
Problem Name: Construct Uniform Parity Array I

LeetCode Link:
https://leetcode.com/problems/construct-uniform-parity-array-i/

Difficulty: Easy

Topics:
Array, Math, Parity

Approach:
We need to determine whether nums2 can be constructed such
that all its elements have the same parity (all odd or all even).

The answer is always true.

Steps:

1. If all elements of nums1 have the same parity, we can
   simply choose:

       nums2[i] = nums1[i]

   Therefore, nums2 is already uniform.

2. If both odd and even numbers exist, we can make all
   elements odd.

3. Keep every odd number unchanged.

4. For every even number, choose any odd number nums1[j]
   and use:

       nums2[i] = nums1[i] - nums1[j]

   Since:

       even - odd = odd

   the resulting value is odd.

5. Therefore, regardless of the input, it is always possible
   to construct a uniform parity array.

6. Hence, the function can simply return true.

Time Complexity:
O(1)

Space Complexity:
O(1)
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
