/*
Problem Number: 1081
Problem Name: Smallest Subsequence of Distinct Characters

LeetCode Link:
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Difficulty: Medium

Topics:
String, Stack, Greedy, Monotonic Stack

Approach:
We need to construct the lexicographically
smallest subsequence that contains every
distinct character exactly once.

Steps:

1. Store the last occurrence of every
   character in the string.

2. Maintain a stack (implemented using a
   string) to build the answer.

3. Keep a boolean array to mark characters
   already included in the stack.

4. For each character:
   - Skip it if already present.
   - Otherwise, while the stack is not
     empty, the top character is larger
     than the current character, and it
     appears again later, pop it.
   - Push the current character into the
     stack.

5. The stack finally contains the
   lexicographically smallest subsequence.

Time Complexity:
O(n)

Space Complexity:
O(1)

(Uses constant extra space since the
alphabet size is fixed at 26.)
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        // Last occurrence of every character
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> used(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (used[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};
