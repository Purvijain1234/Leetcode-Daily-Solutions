/*
Problem Number: 3336
Problem Name: Find the Number of Subsequences With Equal GCD

LeetCode Link:
https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/

Difficulty: Hard

Topics:
Dynamic Programming, Math, GCD, Number Theory

Approach:
We process every element one by one.

Each element has three choices:

1. Ignore the element.
2. Add it to the first subsequence.
3. Add it to the second subsequence.

DP State:

dp[g1][g2]

where

g1 = GCD of subsequence 1
g2 = GCD of subsequence 2

Initially:

dp[0][0] = 1

Here GCD = 0 represents an empty subsequence.

Transition:

Ignore:
    dp[g1][g2]

Add to seq1:
    newGCD =
    gcd(g1, x)

Add to seq2:
    newGCD =
    gcd(g2, x)

After processing all numbers,
sum every state where

g1 == g2 > 0

because both subsequences must be
non-empty and have equal GCD.

Time Complexity:
O(n × M² × logM)

where
M = maximum element in nums

Space Complexity:
O(M²)
*/

class Solution {
public:
    static const int MOD = 1000000007;

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp = dp; // Option 1: ignore current element

            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    // Put current element into seq1
                    int ng1 = (g1 == 0 ? x : std::gcd(g1, x));
                    ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;

                    // Put current element into seq2
                    int ng2 = (g2 == 0 ? x : std::gcd(g2, x));
                    ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= mx; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};
