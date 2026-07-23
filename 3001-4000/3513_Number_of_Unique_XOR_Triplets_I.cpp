/*
Problem Number: 3513
Problem Name: Number of Unique XOR Triplets I

LeetCode Link:
https://leetcode.com/problems/number-of-unique-xor-triplets-i/

Difficulty: Medium

Topics:
Bit Manipulation, Math, Array

Approach:
Observe the pattern in the number of
distinct XOR values obtainable from all
triplets.

Cases:

1. If n = 1:
   Only one XOR value is possible.

2. If n = 2:
   Exactly two distinct XOR values exist.

3. If n >= 3:
   Let bits be the number of bits required
   to represent n.

   The distinct XOR values cover all
   integers representable using these bits.

   Therefore, the answer is:

       2^bits

Compute the number of bits in n and return:

       (1 << bits)

Time Complexity:
O(log n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;
        if (n == 2) return 2;

        int bits = 0;
        int x = n;
        while (x) {
            bits++;
            x >>= 1;
        }

        return 1 << bits;
    }
};
