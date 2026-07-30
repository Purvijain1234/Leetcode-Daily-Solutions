/*
Problem Number: 3014
Problem Name: Minimum Number of Pushes to Type Word I

LeetCode Link:
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/

Difficulty: Easy

Topics:
Greedy, String, Math

Approach:
The keyboard has 8 keys available for
assigning characters.

To minimize the total number of pushes:

1. Assign the first 8 characters to
   require 1 push.

2. Assign the next 8 characters to
   require 2 pushes.

3. Continue assigning characters in
   groups of 8.

For the i-th character (0-indexed),
the number of pushes required is:

    (i / 8) + 1

Sum this value for every character
to obtain the minimum number of pushes.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            ans += (i / 8) + 1;
        }
        return ans;
    }
};
