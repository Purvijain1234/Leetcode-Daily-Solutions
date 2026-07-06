/*
Problem Number: 1288
Problem Name: Remove Covered Intervals

LeetCode Link:
https://leetcode.com/problems/remove-covered-intervals/

Difficulty: Medium

Topics:
Array, Sorting, Greedy

Approach:
An interval [a, b] is covered by another
interval [c, d] if:

c <= a
and
b <= d

Steps:
1. Sort intervals by:
   - Increasing start point.
   - If starts are equal,
     decreasing end point.

   This ensures larger intervals come
   before smaller ones when they start
   at the same position.

2. Traverse the sorted intervals while
   maintaining the maximum end point
   seen so far.

3. If the current interval extends beyond
   maxEnd, it is not covered:
      - Count it.
      - Update maxEnd.

4. Otherwise, the interval is covered
   by a previous interval.

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(excluding sorting space)
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];   // larger end first
                 return a[0] < b[0];       // smaller start first
             });

        int count = 0;
        int maxEnd = 0;

        for (auto &interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};
