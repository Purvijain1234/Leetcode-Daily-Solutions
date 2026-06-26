/*
Problem Number: 3739
Problem Name: Count Subarrays With Majority Element II

LeetCode Link:
https://leetcode.com/problems/count-subarrays-with-majority-element-ii/

Difficulty: Hard

Topics:
Array, Prefix Sum, Fenwick Tree (Binary Indexed Tree),
Coordinate Compression, Data Structures

Approach:
A subarray has target as the majority element if:

count(target) > count(other elements)

Transform the array:

target      → +1
other value → -1

Now, the problem reduces to counting
subarrays whose transformed sum is
strictly positive.

Steps:
1. Convert the array into +1 and -1 values.
2. Compute prefix sums.
3. Prefix sums can be negative and large,
   so perform Coordinate Compression.
4. Maintain frequencies of previous
   prefix sums using a Fenwick Tree.
5. For each prefix sum:
      Count previous prefix sums that are
      strictly smaller than the current one.
6. Add the count to the answer and
   insert the current prefix sum into
   the Fenwick Tree.

Time Complexity:
O(n log n)

Space Complexity:
O(n)
*/

class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick bit(comp.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
            ans += bit.query(idx - 1);   // count previous prefix sums < current
            bit.update(idx, 1);
        }

        return ans;
    }
};
