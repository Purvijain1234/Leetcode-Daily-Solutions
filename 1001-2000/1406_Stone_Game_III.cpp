/*
Problem Number: 1406
Problem Name: Stone Game III

LeetCode Link:
https://leetcode.com/problems/stone-game-iii/

Difficulty: Hard

Topics:
Dynamic Programming, Game Theory, Array

Approach:
Both Alice and Bob play optimally.

Instead of storing each player's score,
store the maximum score difference
(current player - opponent) starting
from each index.

Let:

    dp[i]

represent the maximum score difference
the current player can obtain starting
from index i.

At each turn, the player can take
1, 2, or 3 stones.

Transition:

1. Take one stone:
      stoneValue[i] - dp[i+1]

2. Take two stones:
      stoneValue[i] + stoneValue[i+1]
      - dp[i+2]

3. Take three stones:
      stoneValue[i] + stoneValue[i+1]
      + stoneValue[i+2]
      - dp[i+3]

Choose the option giving the maximum
score difference.

Finally:

dp[0] > 0  -> Alice wins
dp[0] < 0  -> Bob wins
dp[0] = 0  -> Tie

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        // dp[n] = 0 (no stones left)

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int take = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
