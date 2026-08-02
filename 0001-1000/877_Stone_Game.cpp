/*
Problem Number: 877
Problem Name: Stone Game

LeetCode Link:
https://leetcode.com/problems/stone-game/

Difficulty: Medium

Topics:
Dynamic Programming, Game Theory, Array

Approach:
Both Alice and Bob play optimally.

Instead of storing the maximum stones,
store the maximum score difference
(current player - opponent) for every
subarray.

Let:

    dp[i][j]

represent the maximum score difference
the current player can achieve from
piles[i...j].

Transition:

1. Pick the left pile:

       piles[i] - dp[i+1][j]

2. Pick the right pile:

       piles[j] - dp[i][j-1]

Take the maximum of the two choices.

If the final score difference is positive,
Alice collects more stones than Bob and
wins.

Time Complexity:
O(n²)

Space Complexity:
O(n²)
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(
                    piles[i] - dp[i + 1][j],
                    piles[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};
