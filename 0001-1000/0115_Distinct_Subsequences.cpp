/*
Problem Number: 115
Problem Name: Distinct Subsequences

LeetCode Link:
https://leetcode.com/problems/distinct-subsequences/

Difficulty: Hard

Topics:
String, Dynamic Programming

Approach:
We need to count the number of distinct subsequences of
string s that are equal to string t.

Steps:

1. Let dp[j] represent the number of ways to form the first
   j characters of t using the characters processed so far
   from s.

2. Initialize:

       dp[0] = 1

   There is exactly one way to form an empty string:
   by choosing no characters.

3. Traverse each character of s.

4. Traverse t from right to left.

   If:

       s[i - 1] == t[j - 1]

   then the current character can either be used to form
   t[j - 1] or skipped.

5. The transition is:

       dp[j] += dp[j - 1]

6. We iterate j from right to left so that dp[j - 1]
   still represents the previous state and is not overwritten
   during the current iteration.

7. If t is longer than s, it is impossible to form t, so
   return 0.

8. The final value dp[n] gives the number of distinct
   subsequences of s that equal t.

9. The value is capped at INT_MAX in the implementation to
   safely stay within the required 32-bit return range.

Time Complexity:
O(m × n)

Space Complexity:
O(n)

where:
m = length of s
n = length of t
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (n > m) return 0;

        const long long LIMIT = INT_MAX;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = min(i, n); j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    if (dp[j] > LIMIT - dp[j - 1]) {
                        dp[j] = LIMIT;
                    } else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        return (int)dp[n];
    }
};

