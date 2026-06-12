/*
Problem Number: 3559
Problem Name:  Number of Ways to Assign Edge Weights II

LeetCode Link:
https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii

Difficulty: Hard

Topics:
Tree, Graph, LCA, Binary Lifting,
DFS, Math, Binary Exponentiation

Approach:
For every query (u, v):

1. Find the Lowest Common Ancestor (LCA)
   of u and v using Binary Lifting.

2. Compute the path length:

   dist =
   depth[u] + depth[v]
   - 2 × depth[lca]

3. Number of valid assignments:

   2^(dist - 1)

4. Precompute powers of 2 modulo 1e9+7
   for fast query processing.

Time Complexity:
Preprocessing:
O(n log n)

Each Query:
O(log n)

Total:
O((n + q) log n)

Space Complexity:
O(n log n)
*/

class Solution {
public:

    static constexpr long long MOD =
        1'000'000'007LL;

    vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        // Build Tree
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int LOG = 17;

        while((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>>
            up(LOG,
               vector<int>(n + 1, 0));

        vector<int> depth(n + 1, 0);

        // DFS for depth and parents
        function<void(int,int)> dfs =
            [&](int u, int p) {

            up[0][u] = p;

            for(int v : g[u]) {

                if(v == p) {
                    continue;
                }

                depth[v] =
                    depth[u] + 1;

                dfs(v, u);
            }
        };

        dfs(1, 0);

        // Binary Lifting Table
        for(int j = 1; j < LOG; j++) {

            for(int i = 1; i <= n; i++) {

                up[j][i] =
                    up[j - 1]
                      [up[j - 1][i]];
            }
        }

        // LCA Query
        auto lca = [&](int a, int b) {

            if(depth[a] < depth[b]) {
                swap(a, b);
            }

            int diff =
                depth[a] - depth[b];

            for(int j = LOG - 1;
                j >= 0;
                j--) {

                if(diff & (1 << j)) {

                    a = up[j][a];
                }
            }

            if(a == b) {
                return a;
            }

            for(int j = LOG - 1;
                j >= 0;
                j--) {

                if(up[j][a] != up[j][b]) {

                    a = up[j][a];
                    b = up[j][b];
                }
            }

            return up[0][a];
        };

        // Powers of 2
        vector<long long>
            pow2(n + 1, 1);

        for(int i = 1; i <= n; i++) {

            pow2[i] =
                (pow2[i - 1] * 2)
                % MOD;
        }

        vector<int> ans;

        ans.reserve(
            queries.size()
        );

        for(auto &q : queries) {

            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            int dist =
                depth[u]
                + depth[v]
                - 2 * depth[w];

            if(dist == 0) {

                ans.push_back(0);
            }

            else {

                ans.push_back(
                    (int)pow2[dist - 1]
                );
            }
        }

        return ans;
    }
};
