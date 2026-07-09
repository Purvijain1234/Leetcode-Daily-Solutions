/*
Problem Number: 3532
Problem Name: Path Existence Queries in a Graph I

LeetCode Link:
https://leetcode.com/problems/path-existence-queries-in-a-graph-i/

Difficulty: Medium

Topics:
Graph, Connected Components, Array

Approach:
The array nums is already sorted.

An edge exists between two nodes if:

|nums[i] - nums[j]| <= maxDiff

Observation:

If the difference between two consecutive
elements is greater than maxDiff, the graph
is split into different connected components.

Steps:
1. Traverse the sorted array.
2. Assign a component ID to each index.
3. If:
      nums[i] - nums[i-1] > maxDiff
   start a new component.
4. For each query:
   - If both nodes belong to the same
     component, a path exists.
   - Otherwise, no path exists.

Time Complexity:
Preprocessing:
O(n)

Each Query:
O(1)

Overall:
O(n + q)

Space Complexity:
O(n)
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};
