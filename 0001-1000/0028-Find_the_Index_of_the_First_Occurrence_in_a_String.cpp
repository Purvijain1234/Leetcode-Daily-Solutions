/*
Problem Number: 0028
Problem Name: Find the Index of the First Occurrence in a String

LeetCode Link:
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Difficulty: Easy

Topics:
String, Two Pointers

Approach:
Traverse the haystack string and
check whether the substring starting
from current index matches needle.

If all characters match:
return starting index.

Otherwise:
continue searching.

Time Complexity:
O((n - m + 1) × m)

n = length of haystack
m = length of needle

Space Complexity:
O(1)
*/

class Solution {
public:

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        // Traverse possible starting indices
        for(int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare characters
            while(j < m &&
                  haystack[i + j] == needle[j]) {

                j++;
            }

            // Full match found
            if(j == m) {

                return i;
            }
        }

        return -1;
    }
};
