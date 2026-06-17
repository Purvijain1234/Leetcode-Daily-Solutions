/*
Problem Number: 3612
Problem Name: Process String with Special Operations I

LeetCode Link:
https://leetcode.com/problems/process-string-with-special-operations-i/

Difficulty: Easy

Topics:
String, Simulation, Stack

Approach:
Traverse the string character by character.

Operations:
1. Lowercase letter:
   - Append to result.

2. '*':
   - Remove last character from result
     if it exists.

3. '#':
   - Duplicate the current result.

4. '%':
   - Reverse the current result.

Return the final processed string.

Time Complexity:
O(n + total_generated_characters)

Space Complexity:
O(total_generated_characters)
*/

class Solution {
public:

    string processStr(string s) {

        string result;

        for(char c : s) {

            // Append character
            if(c >= 'a' && c <= 'z') {

                result.push_back(c);
            }

            // Delete last character
            else if(c == '*') {

                if(!result.empty()) {

                    result.pop_back();
                }
            }

            // Duplicate string
            else if(c == '#') {

                result += result;
            }

            // Reverse string
            else if(c == '%') {

                reverse(
                    result.begin(),
                    result.end()
                );
            }
        }

        return result;
    }
};
