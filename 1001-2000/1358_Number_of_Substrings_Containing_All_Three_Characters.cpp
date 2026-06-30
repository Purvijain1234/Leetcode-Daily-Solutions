/*
Problem Number: 1358
Problem Name: Number of Substrings Containing All Three Characters

LeetCode Link:
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Difficulty: Medium

Topics:
String, Sliding Window, Two Pointers

Approach:
We use the Sliding Window technique.

1. Expand the window by moving the
   right pointer and count the frequency
   of 'a', 'b', and 'c'.

2. Once the current window contains
   at least one of each character,
   every substring starting from the
   current left pointer and ending at
   right or beyond is valid.

3. Add:
      (n - right)
   to the answer.

4. Shrink the window by moving the
   left pointer until the window is
   no longer valid.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> cnt(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - right);
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};
