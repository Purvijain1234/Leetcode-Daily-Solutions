/*
Problem Number: 1291
Problem Name: Sequential Digits

LeetCode Link:
https://leetcode.com/problems/sequential-digits/

Difficulty: Medium

Topics:
Math, Enumeration, String

Approach:
A sequential digit number consists of digits
that increase by exactly 1.

Example:
123, 2345, 6789

Observation:
There are only a limited number of sequential
digit numbers.

Use the string:

    "123456789"

Generate every possible substring of lengths
2 to 9.

For each substring:
1. Convert it to an integer.
2. If it lies in the range [low, high],
   add it to the answer.

Since numbers are generated in increasing
order, the final list is already sorted.

Time Complexity:
O(1)

(Only 36 numbers are generated.)

Space Complexity:
O(1)
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {
                int num = stoi(s.substr(i, len));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};
