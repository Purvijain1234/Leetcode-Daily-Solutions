/*
Problem Number: 486
Problem Name: Predict the Winner

LeetCode Link:
https://leetcode.com/problems/predict-the-winner/

Difficulty: Medium

Topics:
Dynamic Programming, Game Theory, Array

Approach:
Both players play optimally.

Let dp[i][j] represent the maximum score
difference (current player - opponent)
that the current player can achieve
from the subarray nums[i...j].

Transition:

1. Pick the left element:
      nums[i] - dp[i+1][j]

2. Pick the right element:
      nums[j] - dp[i][j-1]

Choose the better option:

      dp[i][j] =
      max(takeLeft, takeRight)

Base Case:

dp[i][i] = nums[i]

If the final score difference is
non-negative, Player 1 can win
(or tie).

Time Complexity:
O(n²)

Space Complexity:
O(n²)
*/

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one element
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        // Fill DP table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                int takeLeft = nums[i] - dp[i + 1][j];
                int takeRight = nums[j] - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
