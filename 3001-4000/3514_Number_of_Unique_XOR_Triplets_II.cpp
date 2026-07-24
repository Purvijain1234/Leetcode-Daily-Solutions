/*
Problem Number: 3514
Problem Name: Number of Unique XOR Triplets II

LeetCode Link:
https://leetcode.com/problems/number-of-unique-xor-triplets-ii/

Difficulty: Medium

Topics:
Bit Manipulation, Array, Hashing

Approach:
We need to count the number of distinct
values obtainable by XORing any three
elements from the array.

Steps:

1. Find the maximum value in nums to
   determine the required XOR range.

2. Compute every possible XOR of two
   elements and store whether each value
   is achievable.

3. For every achievable XOR of two
   elements, XOR it with every element
   in nums to generate XOR values of
   three elements.

4. Count the number of distinct XOR
   values obtained.

Time Complexity:
O(n² + V × n)

where:
n = size of nums
V = maximum possible XOR value

Space Complexity:
O(V)
*//*
Problem Number: 3514
Problem Name: Number of Unique XOR Triplets II

LeetCode Link:
https://leetcode.com/problems/number-of-unique-xor-triplets-ii/

Difficulty: Medium

Topics:
Bit Manipulation, Array, Hashing

Approach:
We need to count the number of distinct
values obtainable by XORing any three
elements from the array.

Steps:

1. Find the maximum value in nums to
   determine the required XOR range.

2. Compute every possible XOR of two
   elements and store whether each value
   is achievable.

3. For every achievable XOR of two
   elements, XOR it with every element
   in nums to generate XOR values of
   three elements.

4. Count the number of distinct XOR
   values obtained.

Time Complexity:
O(n² + V × n)

where:
n = size of nums
V = maximum possible XOR value

Space Complexity:
O(V)
*/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()) << 1;

        // st[x] = whether x can be obtained as XOR of two elements
        vector<bool> st(mx, false);
        for (int a : nums) {
            for (int b : nums) {
                st[a ^ b] = true;
            }
        }

        // ans[x] = whether x can be obtained as XOR of three elements
        vector<bool> ans(mx, false);
        for (int x = 0; x < mx; x++) {
            if (!st[x]) continue;
            for (int c : nums) {
                ans[x ^ c] = true;
            }
        }

        return count(ans.begin(), ans.end(), true);
    }
};
