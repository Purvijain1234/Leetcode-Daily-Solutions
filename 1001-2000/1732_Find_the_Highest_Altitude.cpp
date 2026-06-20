/*
Problem Number: 1732
Problem Name: Find the Highest Altitude

LeetCode Link:
https://leetcode.com/problems/find-the-highest-altitude/

Difficulty: Easy

Topics:
Array, Prefix Sum

Approach:
The biker starts at altitude 0.

For each gain:
1. Add gain to current altitude.
2. Track the maximum altitude reached.

Return the highest altitude encountered.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int maxAltitude = 0;

        for(int g : gain) {

            altitude += g;

            maxAltitude =
                max(maxAltitude,
                    altitude);
        }

        return maxAltitude;
    }
};
