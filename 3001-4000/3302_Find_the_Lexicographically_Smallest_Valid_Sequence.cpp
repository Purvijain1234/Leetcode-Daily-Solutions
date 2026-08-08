/*
Problem Number: 3302
Problem Name: Find the Lexicographically Smallest Valid Sequence

LeetCode Link:
https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/

Difficulty: Medium

Topics:
Two Pointers, String, Greedy

Approach:
We need to find the lexicographically smallest sequence of
indices from word1 such that the characters selected form
a string that can be made equal to word2 by changing at
most one character.

Steps:

1. We need to select exactly word2.length characters from
   word1 while keeping their indices in increasing order.

2. First, scan word1 from right to left and build the `last`
   array.

   last[j] stores the latest index in word1 where word2[j]
   can be matched while still allowing word2[j+1...]
   to be matched afterward.

3. Now scan word1 from left to right.

4. If word1[i] matches word2[j], select index i normally.

5. Otherwise, we can use our one allowed mismatch.

   We can select i as a mismatch only if the remaining
   characters of word2 can still be matched afterward.

   This is checked using:

   j == m - 1 || i < last[j + 1]

6. Once the mismatch is used, all remaining characters must
   match normally.

7. Since we scan word1 from left to right and always select
   the earliest possible valid index, the resulting sequence
   is lexicographically smallest.

8. If we cannot match all characters of word2, return an
   empty array.

Time Complexity:
O(n + m)

Space Complexity:
O(m)

where:
n = length of word1
m = length of word2
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = the latest index in word1 where word2[j]
        // can be matched while still matching word2[j+1...].
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans(m);

        j = 0;
        bool usedMismatch = false;

        for (i = 0; i < n && j < m; i++) {

            // Normal matching character.
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch.
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j] = i;
                j++;
                usedMismatch = true;
            }
        }

        // Could not form a valid sequence.
        if (j != m)
            return {};

        return ans;
    }
};
