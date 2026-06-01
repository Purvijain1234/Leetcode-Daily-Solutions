/*
Problem Number: 2144
Problem Name: Minimum Cost of Buying Candies With Discount

LeetCode Link:
https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

Difficulty: Easy

Topics:
Array, Greedy, Sorting

Approach:
Sort candies in descending order.

For every group of 3 candies:
- Pay for the two most expensive candies
- Get the third candy (cheapest in the group) for free

Add the cost of all candies except every
third candy after sorting.

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(ignoring sorting space)
*/

class Solution {
public:

    int minimumCost(vector<int>& cost) {

        // Sort in descending order
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for(int i = 0; i < cost.size(); i++) {

            // Every third candy is free
            if((i + 1) % 3 != 0) {

                ans += cost[i];
            }
        }

        return ans;
    }
};
