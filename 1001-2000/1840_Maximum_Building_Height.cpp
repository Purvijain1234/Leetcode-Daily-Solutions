/*
Problem Number: 1840
Problem Name: Maximum Building Height

LeetCode Link:
https://leetcode.com/problems/maximum-building-height/

Difficulty: Hard

Topics:
Array, Greedy, Math, Sorting

Approach:
Each building height must satisfy:

|height[i] - height[i-1]| ≤ 1

Restrictions give maximum allowed heights
for specific buildings.

Steps:

1. Add building 1 with height 0.
2. Sort restrictions by building index.
3. Add building n if not present.
4. Propagate constraints:
   - Left → Right
   - Right → Left
5. For every adjacent restriction pair:
   calculate the highest possible peak
   between them.

Peak formula:

peak =
(h1 + h2 + distance) / 2

Take maximum over all segments.

Time Complexity:
O(m log m)

m = number of restrictions

Space Complexity:
O(1)
(excluding input storage)
*/

class Solution {
public:

    int maxBuilding(
        int n,
        vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        sort(
            restrictions.begin(),
            restrictions.end()
        );

        int m = restrictions.size();

        // Add restriction for building n
        if(restrictions.back()[0] != n) {

            int maxH =
                restrictions.back()[1]
                + (n - restrictions.back()[0]);

            restrictions.push_back(
                {n, maxH}
            );

            m++;
        }

        // Left → Right pass
        for(int i = 1; i < m; i++) {

            restrictions[i][1] =
                min(
                    restrictions[i][1],
                    restrictions[i - 1][1]
                    + (restrictions[i][0]
                    - restrictions[i - 1][0])
                );
        }

        // Right → Left pass
        for(int i = m - 2; i >= 0; i--) {

            restrictions[i][1] =
                min(
                    restrictions[i][1],
                    restrictions[i + 1][1]
                    + (restrictions[i + 1][0]
                    - restrictions[i][0])
                );
        }

        long long ans = 0;

        // Maximum peak between restrictions
        for(int i = 1; i < m; i++) {

            long long x1 =
                restrictions[i - 1][0];

            long long h1 =
                restrictions[i - 1][1];

            long long x2 =
                restrictions[i][0];

            long long h2 =
                restrictions[i][1];

            long long dist =
                x2 - x1;

            long long peak =
                (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};
