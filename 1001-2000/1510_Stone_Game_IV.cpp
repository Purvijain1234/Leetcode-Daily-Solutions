/*
Problem Number: 1510
Problem Name: Stone Game IV

LeetCode Link:
https://leetcode.com/problems/stone-game-iv/

Difficulty: Hard

Topics:
Math, Dynamic Programming, Game Theory

Approach:
We need to determine whether the first player can win
the game when there are n stones.

Steps:

1. Use Dynamic Programming.

   dp[i] = true if the current player can win when
   there are exactly i stones remaining.

2. Initialize:

   dp[0] = false

   If there are no stones left, the current player cannot
   make any move, so the current player loses.

3. For every number of stones i from 1 to n, try removing
   every possible perfect square:

   1², 2², 3², ...

   as long as j² <= i.

4. After removing j² stones, the opponent gets:

   i - j²

   stones.

5. If dp[i - j²] is false, it means the opponent is in a
   losing position.

   Therefore, the current player can make this move and win:

   dp[i] = true

6. If every possible move gives the opponent a winning
   position, then dp[i] remains false.

7. Finally, return dp[n].

Time Complexity:
O(n × √n)

Space Complexity:
O(n)

where:
n = number of stones
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true if the current player can win with i stones
        // dp[0] = false because no move is possible

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // If removing j*j leaves the opponent in a losing state,
                // the current player wins.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
