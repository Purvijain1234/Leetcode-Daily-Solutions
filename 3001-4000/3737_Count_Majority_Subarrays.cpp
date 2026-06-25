/*
Problem Number: 3737
Problem Name: Count Majority Subarrays

LeetCode Link:
https://leetcode.com/problems/count-majority-subarrays/

Difficulty: Hard

Topics:
Array, Prefix Sum, Fenwick Tree (Binary Indexed Tree),
Data Structures

Approach:
A subarray has target as the majority element if:

count(target) > count(other elements)

Transform the array:

target      → +1
other value → -1

Now the problem becomes counting the
number of subarrays whose sum is positive.

Steps:
1. Replace:
      target -> +1
      others -> -1

2. Compute prefix sums.

3. Maintain frequencies of previous
   prefix sums using a Fenwick Tree.

4. For every prefix:
      Count previous prefix sums that are
      strictly smaller than the current one.

5. Add this count to the answer and
   insert the current prefix into the BIT.

Time Complexity:
O(n log n)

Space Complexity:
O(n)
*/

class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;

        Fenwick bit(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        // Empty prefix sum
        bit.update(pref + offset, 1);

        for (int x : nums) {
            pref += (x == target ? 1 : -1);

            // Count previous prefix sums strictly smaller
            ans += bit.query(pref + offset - 1);

            bit.update(pref + offset, 1);
        }

        return (int)ans;
    }
};
