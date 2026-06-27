/*
Problem Number: 3020
Problem Name: Find the Maximum Number of Elements in Subset

LeetCode Link:
https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/

Difficulty: Medium

Topics:
Array, Hash Table, Greedy, Math

Approach:
The required subset must follow the pattern:

[x, x², x⁴, ..., xᵏ, ..., x⁴, x², x]

Observations:

1. Every element except the middle element
   must appear at least twice because the
   sequence is symmetric.

2. Count the frequency of every number
   using a Hash Map.

3. Handle the special case of value 1:
   Since 1² = 1, we can only use an odd
   number of 1's.

4. For every distinct starting value x:
   - Continue squaring:
       x → x² → x⁴ → ...
   - While there are at least two copies,
     add two elements to the answer.
   - The last valid value contributes one
     element as the center of the sequence.

5. Track the maximum valid subset length.

Time Complexity:
O(n log log M)

where M is the maximum value in nums.

Space Complexity:
O(n)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;
                if (cur > 1000000000LL / cur) break; // avoid overflow
                cur = cur * cur;
            }

            if (freq.count(cur))
                len++;      // use one copy at the peak
            else
                len--;      // last pair cannot be completed

            ans = max(ans, len);
        }

        return ans;
    }
};
