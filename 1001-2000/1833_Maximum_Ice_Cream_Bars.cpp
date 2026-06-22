/*
Problem Number: 1833
Problem Name: Maximum Ice Cream Bars

LeetCode Link:
https://leetcode.com/problems/maximum-ice-cream-bars/

Difficulty: Medium

Topics:
Array, Greedy, Counting Sort

Approach:
To maximize the number of ice cream bars:

1. Buy the cheapest bars first.
2. Instead of sorting, use Counting Sort.
3. Count the frequency of each cost.
4. Traverse costs from smallest to largest.
5. Buy as many bars as possible for each cost.

This is faster than normal sorting when
cost values are limited.

Time Complexity:
O(n + maxCost)

Space Complexity:
O(maxCost)
*/

class Solution {
public:

    int maxIceCream(
        vector<int>& costs,
        int coins) {

        int maxCost =
            *max_element(
                costs.begin(),
                costs.end()
            );

        vector<int> freq(
            maxCost + 1,
            0
        );

        // Count frequencies
        for(int cost : costs) {

            freq[cost]++;
        }

        int count = 0;

        // Buy cheapest first
        for(int cost = 1;
            cost <= maxCost &&
            coins >= cost;
            cost++) {

            if(freq[cost] == 0) {
                continue;
            }

            int canBuy =
                min(
                    freq[cost],
                    coins / cost
                );

            count += canBuy;

            coins -=
                canBuy * cost;
        }

        return count;
    }
};
