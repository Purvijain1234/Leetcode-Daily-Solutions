/*
Problem Number: 1140
Problem Name: Stone Game II

LeetCode Link:
https://leetcode.com/problems/stone-game-ii/

Difficulty: Medium

Topics:
Array, Dynamic Programming, Game Theory, Prefix Sum

Approach:
We need to determine the maximum number of stones the
current player can collect when players take turns picking
piles from the beginning.

Steps:

1. Build a suffix sum array.

   suffix[i] stores the total number of stones from
   pile i to the end.

2. Define:

   dp[i][M] = maximum number of stones the current player
   can collect starting from index i when the current
   value of M is M.

3. At every state, the current player can take X piles where:

   1 <= X <= 2 * M

4. After taking X piles, the value of M becomes:

   max(M, X)

5. If the current player takes all remaining piles, they
   simply get the entire remaining suffix.

6. Otherwise, suppose the total remaining stones are
   suffix[i].

   If the opponent can get dp[i + X][nextM] stones from
   the remaining piles, then the current player gets:

   suffix[i] - dp[i + X][nextM]

7. Try every possible value of X and take the maximum:

   dp[i][M] =
   max(suffix[i] - dp[i + X][max(M, X)])

8. Fill the DP table from right to left because every state
   depends on a later index.

9. The game starts at index 0 with M = 1, so the answer is:

   dp[0][1]

Time Complexity:
O(n^3)

Space Complexity:
O(n^2)

where:
n = number of piles
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones the current player can get
        // starting from index i with current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                // Can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                // Try taking X piles, where 1 <= X <= 2*M
                for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                    int nextM = max(M, X);

                    // Current player gets the stones not obtainable
                    // by the opponent from the remaining suffix.
                    int current = suffix[i] - dp[i + X][nextM];

                    best = max(best, current);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};
