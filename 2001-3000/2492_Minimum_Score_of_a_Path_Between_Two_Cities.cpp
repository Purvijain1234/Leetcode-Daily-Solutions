/*
Problem Number: 2492
Problem Name: Minimum Score of a Path Between Two Cities

LeetCode Link:
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

Difficulty: Medium

Topics:
Graph, Depth-First Search (DFS), Breadth-First Search (BFS)

Approach:
The score of a path is defined as the
minimum edge weight on that path.

Observation:
Since the graph is connected through
multiple paths, every city reachable
from city 1 belongs to the same connected
component.

The answer is simply the minimum edge
weight among all roads in the connected
component containing city 1.

Steps:
1. Build an adjacency list.
2. Perform DFS starting from city 1.
3. During traversal, update the minimum
   edge weight encountered.
4. Return the minimum value.

Time Complexity:
O(n + m)

where:
n = number of cities
m = number of roads

Space Complexity:
O(n + m)
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        int ans = INT_MAX;

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto &[v, w] : adj[u]) {
                ans = min(ans, w);
                if (!vis[v]) dfs(v);
            }
        };

        dfs(1);
        return ans;
    }
};
