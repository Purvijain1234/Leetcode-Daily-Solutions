/*
Problem Number: 1301
Problem Name: Number of Paths with Max Score

LeetCode Link:
https://leetcode.com/problems/number-of-paths-with-max-score/

Difficulty: Hard

Topics:
Dynamic Programming, Matrix

Approach:
We use Dynamic Programming to compute:

1. score[i][j]
   = Maximum score obtainable from
     cell (i, j) to the destination (S).

2. ways[i][j]
   = Number of paths that achieve
     score[i][j].

Initialization:
- Start from 'S' (bottom-right).
- score[S] = 0
- ways[S] = 1

Transition:
For every cell, consider three possible
moves:

- Down
- Right
- Diagonal Down-Right

(Equivalent to moving Up, Left and
Up-Left from S.)

Among all reachable neighbors:
- Choose the maximum score.
- If multiple neighbors have the same
  maximum score, add their path counts.

If current cell contains a digit,
add its value to the score.

If no valid path exists,
return {0, 0}.

Time Complexity:
O(n²)

Space Complexity:
O(n²)
*/

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        const int NEG = -1;

        vector<vector<int>> score(n, vector<int>(n, NEG));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = NEG;
                long long cnt = 0;

                vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};

                for (auto &d : dirs) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= n || nj >= n) continue;
                    if (score[ni][nj] == NEG) continue;

                    if (score[ni][nj] > best) {
                        best = score[ni][nj];
                        cnt = ways[ni][nj];
                    } else if (score[ni][nj] == best) {
                        cnt = (cnt + ways[ni][nj]) % MOD;
                    }
                }

                if (best == NEG) continue;

                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9')
                    val = board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if (ways[0][0] == 0) return {0, 0};
        return {score[0][0], ways[0][0]};
    }
};
