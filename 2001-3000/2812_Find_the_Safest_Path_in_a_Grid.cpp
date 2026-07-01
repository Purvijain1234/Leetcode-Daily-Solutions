/*
Problem Number: 2812
Problem Name: Find the Safest Path in a Grid

LeetCode Link:
https://leetcode.com/problems/find-the-safest-path-in-a-grid/

Difficulty: Medium

Topics:
Graph, Breadth-First Search (BFS), Binary Search,
Matrix

Approach:
The solution consists of two phases.

Phase 1: Multi-Source BFS
-------------------------
1. Push all thief cells into the queue.
2. Perform BFS simultaneously from every thief.
3. Compute the minimum Manhattan distance
   from every cell to its nearest thief.

The resulting matrix 'dist' stores the
"safeness" of every cell.

Phase 2: Binary Search + BFS
----------------------------
Binary search on the answer (minimum safeness).

For each candidate safeness factor:
1. Start BFS from (0,0).
2. Only move through cells whose
   distance to the nearest thief is
   at least the candidate value.
3. If (n-1,n-1) is reachable,
   increase the answer.
4. Otherwise decrease it.

Time Complexity:
Multi-Source BFS : O(n²)
Binary Search    : O(log n)
BFS per check    : O(n²)

Overall:
O(n² log n)

Space Complexity:
O(n²)
*/
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto canReach = [&](int safe) {
            if(dist[0][0] < safe) return false;

            vector<vector<int>> vis(n, vector<int>(n, 0));
            queue<pair<int,int>> qq;

            qq.push({0,0});
            vis[0][0] = 1;

            while(!qq.empty()) {
                auto [x, y] = qq.front();
                qq.pop();

                if(x == n-1 && y == n-1)
                    return true;

                for(auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                       !vis[nx][ny] &&
                       dist[nx][ny] >= safe) {
                        vis[nx][ny] = 1;
                        qq.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int low = 0, high = 2 * n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};
