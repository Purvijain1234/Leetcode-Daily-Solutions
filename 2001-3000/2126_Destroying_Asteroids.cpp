/*
Problem Number: 2126
Problem Name: Destroying Asteroids

LeetCode Link:
https://leetcode.com/problems/destroying-asteroids/

Difficulty: Medium

Topics:
Array, Greedy, Sorting

Approach:
Sort all asteroids in ascending order.

Always destroy the smallest asteroid first.
If current mass is greater than or equal to
the asteroid's mass, destroy it and add its
mass to the current planet mass.

If at any point an asteroid is larger than
the current mass, it cannot be destroyed.

Time Complexity:
O(n log n)

Space Complexity:
O(1)
(ignoring sorting space used by STL)
*/

class Solution {
public:

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        // Use long long to prevent overflow
        long long currMass = mass;

        for(int asteroid : asteroids) {

            // Cannot destroy asteroid
            if(currMass < asteroid) {
                return false;
            }

            // Destroy asteroid and gain mass
            currMass += asteroid;
        }

        return true;
    }
};
