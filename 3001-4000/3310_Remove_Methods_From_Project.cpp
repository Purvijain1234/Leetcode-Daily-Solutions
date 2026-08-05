/*
Problem Number: 3310
Problem Name: Remove Methods From Project

LeetCode Link:
https://leetcode.com/problems/remove-methods-from-project/

Difficulty: Medium

Topics:
Graph, BFS, DFS

Approach:
We need to determine which methods can
be removed after method k becomes
suspicious.

Steps:

1. Build a directed graph from the
   invocation list.

2. Perform BFS (or DFS) starting from
   method k to mark every method that is
   reachable. These methods form the
   suspicious group.

3. Check every invocation:
      u -> v

   If:
      u is NOT suspicious
      AND
      v IS suspicious

   then a safe method depends on a
   suspicious method, so the suspicious
   group cannot be removed.

   In this case, return all methods.

4. Otherwise, remove every suspicious
   method and return only the remaining
   methods.

Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

where:
n = number of methods
m = number of invocations
*/

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods (reachable from k)
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Check if any outside method invokes a suspicious method
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                // Cannot remove the suspicious group
                vector<int> ans;
                for (int i = 0; i < n; i++) ans.push_back(i);
                return ans;
            }
        }

        // Remove all suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) ans.push_back(i);
        }
        return ans;
    }
};
