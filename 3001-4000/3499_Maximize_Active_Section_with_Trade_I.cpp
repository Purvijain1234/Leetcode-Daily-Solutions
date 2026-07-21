/*
Problem Number: 3499
Problem Name: Maximize Active Section with Trade I

LeetCode Link:
https://leetcode.com/problems/maximize-active-section-with-trade-i/

Difficulty: Medium

Topics:
String, Greedy, Simulation, Run-Length Encoding (RLE)

Approach:
Treat the string as augmented with
'1' at both ends:

    t = "1" + s + "1"

1. Count the number of active sections
   ('1's) in the original string.

2. Perform Run-Length Encoding (RLE) on
   the augmented string to group
   consecutive equal characters.

3. Traverse every internal block of '1's.

4. If a '1' block is surrounded by two
   '0' blocks, removing it merges the
   adjacent zero blocks into one larger
   zero block.

5. Trading this merged zero block into
   ones increases the active sections by
   the sizes of the two neighboring zero
   blocks.

6. Compute the maximum possible active
   sections after one optimal trade.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char, int>> runs;
        int i = 0, m = t.size();

        while (i < m) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        // Check every internal '1' block
        for (int k = 1; k + 1 < runs.size(); k++) {
            if (runs[k].first == '1' &&
                runs[k - 1].first == '0' &&
                runs[k + 1].first == '0') {

                int leftZero = runs[k - 1].second;
                int rightZero = runs[k + 1].second;

                ans = max(ans, ones + leftZero + rightZero);
            }
        }

        return ans;
    }
};
