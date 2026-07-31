/*
Problem Number: 3016
Problem Name: Minimum Number of Pushes to Type Word II

LeetCode Link:
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

Difficulty: Medium

Topics:
Greedy, String, Sorting, Counting

Approach:
Unlike Part I, we can assign letters to
keys in any order.

To minimize the total number of pushes:

1. Count the frequency of every letter.
2. Sort the frequencies in descending
   order.
3. Assign the most frequent letters to
   require the fewest pushes:
      - First 8 letters → 1 push
      - Next 8 letters → 2 pushes
      - Next 8 letters → 3 pushes
      - Remaining letters → 4 pushes
4. Multiply each frequency by its push
   cost and sum the result.

Time Complexity:
O(n + 26 log 26)

≈ O(n)

Space Complexity:
O(26)

≈ O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};
