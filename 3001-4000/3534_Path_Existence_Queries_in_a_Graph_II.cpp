/*
Problem Number: 3534
Problem Name: Path Existence Queries in a Graph II

LeetCode Link:
https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/

Difficulty: Hard

Topics:
Graph, Sorting, Binary Lifting,
Greedy, Array

Approach:
The graph is built using the values in nums,
where an edge exists if the difference
between two values is at most maxDiff.

Steps:

1. Sort the nodes according to their values.

2. Assign each node its position in the
   sorted order.

3. Divide the sorted array into connected
   components.
   Whenever the difference between two
   consecutive values is greater than
   maxDiff, start a new component.

4. For every position, compute the farthest
   position reachable in one move using
   a two-pointer technique.

5. Build a Binary Lifting table where:

      up[k][i]

   represents the farthest position that
   can be reached after 2^k jumps.

6. For every query:
   - If the two nodes belong to different
     components, return -1.
   - Otherwise, use Binary Lifting to find
     the minimum number of jumps required
     to reach the destination.

Time Complexity:

Sorting:
O(n log n)

Preprocessing:
O(n log n)

Each Query:
O(log n)

Overall:
O((n + q) log n)

Space Complexity:
O(n log n)
*/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        vector<int> pos(n), val(n);
        for (int i = 0; i < n; i++) {
            val[i] = v[i].first;
            pos[v[i].second] = i;
        }

        // Find connected components in sorted order.
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        // nxt[i] = farthest index reachable in one step.
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff)
                r++;
            nxt[i] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = pos[q[0]];
            int r = pos[q[1]];
            if (l > r) swap(l, r);

            if (comp[l] != comp[r]) {
                ans.push_back(-1);
                continue;
            }

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            int cur = l;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};
