/*
Problem Number: 3619
Problem Name: Count Edge Weight Assignments I

LeetCode Link:
https://leetcode.com/problems/count-edge-weight-assignments-i/

Difficulty: Medium

Topics:
Tree, Graph, BFS, Math, Binary Exponentiation

Approach:
1. Build the tree using an adjacency list.
2. Perform BFS from node 1 to compute depths.
3. Find the maximum depth in the tree.
4. The number of valid edge-weight assignments is:

    2^(maxDepth - 1)

5. Use Binary Exponentiation to compute
   the answer efficiently under modulo 1e9+7.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:

    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {

        long long res = 1;

        while(b) {

            if(b & 1) {
                res = res * a % MOD;
            }

            a = a * a % MOD;

            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(
        vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        // Build graph
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<int> q;

        vector<int> depth(
            n + 1,
            -1
        );

        q.push(1);

        depth[1] = 0;

        int maxDepth = 0;

        // BFS
        while(!q.empty()) {

            int u = q.front();

            q.pop();

            for(int v : g[u]) {

                if(depth[v] == -1) {

                    depth[v] =
                        depth[u] + 1;

                    maxDepth =
                        max(
                            maxDepth,
                            depth[v]
                        );

                    q.push(v);
                }
            }
        }

        return (int)
            modPow(
                2,
                maxDepth - 1
            );
    }
};
