/*
Problem Number: 1967
Problem Name: Number of Strings That Appear as Substrings in Word

LeetCode Link:
https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

Difficulty: Easy

Topics:
String, String Matching

Approach:
For each pattern:

1. Check whether it appears as a substring
   of the given word using the built-in
   string::find() function.

2. If the substring exists,
   increment the answer.

3. Return the total count.

Time Complexity:
O(p × n × m)

where:
p = number of patterns
n = length of word
m = average length of a pattern

(In practice, std::string::find() is highly optimized.)

Space Complexity:
O(1)
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (string &s : patterns) {
            if (word.find(s) != string::npos)
                count++;
        }
        
        return count;
    }
};
