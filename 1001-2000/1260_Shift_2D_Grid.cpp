/*
Problem Number: 1260
Problem Name: Shift 2D Grid

LeetCode Link:
https://leetcode.com/problems/shift-2d-grid/

Difficulty: Easy

Topics:
Array, Matrix, Simulation

Approach:
Instead of shifting the grid one step at
a time, treat the 2D grid as a flattened
1D array.

Steps:

1. Compute the total number of elements:
      total = m × n

2. Reduce k using modulo:
      k %= total

3. For every element:
   - Convert its (row, col) into a 1D
     index.
   - Compute its new position after
     shifting by k.
   - Convert the new 1D index back into
     2D coordinates.

4. Place the element in its new position.

This simulates all k shifts in a single
traversal.

Time Complexity:
O(m × n)

Space Complexity:
O(m × n)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                int newIdx = (idx + k) % total;

                int r = newIdx / n;
                int c = newIdx % n;

                ans[r][c] = grid[i][j];
            }
        }

        return ans;
    }
};
