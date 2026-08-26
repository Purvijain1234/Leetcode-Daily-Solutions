/*
Problem Number: 2904
Problem Name: Shortest and Lexicographically Smallest Beautiful String

LeetCode Link:
https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

Difficulty: Medium

Topics:
String, Sliding Window, Two Pointers

Approach:
We need to find the shortest substring containing exactly
k occurrences of '1'. If multiple substrings have the same
minimum length, return the lexicographically smallest one.

Steps:

1. Use a sliding window with two pointers:
   - left
   - right

2. Maintain the number of '1's inside the current window.

3. Expand the window by moving right.

4. If the window contains more than k ones, move left
   forward until the number of ones becomes at most k.

5. When the window contains exactly k ones, remove
   unnecessary leading zeros.

   This gives the shortest possible substring ending
   at the current right position.

6. Compare the current substring with the best answer:
   - Prefer the shorter substring.
   - If both have the same length, prefer the
     lexicographically smaller substring.

7. If no substring contains exactly k ones, return "".

Time Complexity:
O(n²)

Space Complexity:
O(n)

where:
n = length of s

Note:
The sliding-window logic performs O(n) pointer movement,
but constructing substrings using substr() can take O(n),
so the overall worst-case complexity is O(n²).
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // Shrink while we have more than k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // If exactly k ones, try to make the substring as short as possible
            if (ones == k) {
                while (left <= right && s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};
