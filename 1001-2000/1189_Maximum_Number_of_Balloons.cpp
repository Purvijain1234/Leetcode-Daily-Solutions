/*
Problem Number: 1189
Problem Name: Maximum Number of Balloons

LeetCode Link:
https://leetcode.com/problems/maximum-number-of-balloons/

Difficulty: Easy

Topics:
String, Hash Table, Counting

Approach:
To form the word:

    "balloon"

Required frequencies:

    b -> 1
    a -> 1
    l -> 2
    o -> 2
    n -> 1

Count frequency of every character in the string.

The maximum number of times we can form
"balloon" is limited by the character
that runs out first.

Answer:

min(
    count(b),
    count(a),
    count(l)/2,
    count(o)/2,
    count(n)
)

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);

        // Count frequencies
        for(char ch : text) {

            freq[ch - 'a']++;
        }

        return min({

            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']

        });
    }
};
