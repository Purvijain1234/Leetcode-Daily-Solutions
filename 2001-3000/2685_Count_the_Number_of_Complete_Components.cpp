/*
Problem Number: 2685
Problem Name: Count the Number of Complete Components

LeetCode Link:
https://leetcode.com/problems/count-the-number-of-complete-components/

Difficulty: Medium

Topics:
Graph, Depth-First Search (DFS), Connected Components

Approach:
A connected component is complete if every
pair of vertices has an edge between them.

Steps:
1. Build the adjacency list.
2. Traverse every connected component
   using DFS.
3. Store all nodes of the component.
4. Let the component size be k.
5. In a complete graph, every node must
   have exactly (k - 1) neighbors.
6. Check the degree of every node:
   - If every node has degree (k - 1),
     the component is complete.
7. Count all complete components.

Time Complexity:
O(n + m)

where:
n = number of vertices
m = number of edges

Space Complexity:
O(n + m)
*/

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& comp, vector<int>& vis) {
        vis[u] = 1;
        comp.push_back(u);

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, comp, vis);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, comp, vis);

                int sz = comp.size();
                bool complete = true;

                for (int node : comp) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    ans++;
            }
        }

        return ans;
    }
};
