/*
Problem Number: 3633
Problem Name: Earliest Finish Time for Land and Water Rides

LeetCode Link:
https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides/

Difficulty: Easy

Topics:
Array, Brute Force, Simulation

Approach:
Try every possible pair of:
- one land ride
- one water ride

For each pair:

1. Land → Water
   - Complete land ride first
   - Wait if water ride has not started
   - Calculate finish time

2. Water → Land
   - Complete water ride first
   - Wait if land ride has not started
   - Calculate finish time

Take the minimum finish time among all combinations.

Time Complexity:
O(n × m)

n = number of land rides
m = number of water rides

Space Complexity:
O(1)
*/

class Solution {
public:

    int earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // Land → Water
                int landFinish =
                    landStartTime[i] + landDuration[i];

                int finish1 =
                    max(waterStartTime[j], landFinish)
                    + waterDuration[j];

                // Water → Land
                int waterFinish =
                    waterStartTime[j] + waterDuration[j];

                int finish2 =
                    max(landStartTime[i], waterFinish)
                    + landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};
