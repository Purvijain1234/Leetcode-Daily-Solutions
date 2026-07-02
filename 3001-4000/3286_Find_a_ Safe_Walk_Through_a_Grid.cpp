/*
Problem Number: 3286
Problem Name: Find a Safe Walk Through a Grid

LeetCode Link:
https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

Difficulty: Medium

Topics:
Graph, Breadth-First Search (BFS), 0-1 BFS,
Deque, Matrix, Shortest Path

Approach:
Moving into:

- Safe cell (0) costs 0 health.
- Unsafe cell (1) costs 1 health.

The goal is to minimize the total health
lost while reaching the destination.

Since every edge weight is either 0 or 1,
we use 0-1 BFS.

Steps:
1. Maintain dist[i][j] =
   minimum health lost to reach cell (i,j).

2. Start from (0,0).

3. If moving into:
   - Safe cell:
       push_front()
   - Unsafe cell:
       push_back()

4. Continue until every shortest cost is found.

5. If minimum health lost is less than the
   initial health, then health remaining is
   at least 1 and the path is valid.

Time Complexity:
O(m × n)

Space Complexity:
O(m × n)
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int nd = dist[x][y] + grid[nx][ny];

                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    if (grid[nx][ny] == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        // Health after reaching destination must be at least 1
        return dist[m - 1][n - 1] < health;
    }
};
