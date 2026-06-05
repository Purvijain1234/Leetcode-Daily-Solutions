/*
Problem Number: 3753
Problem Name: Total Waviness of Numbers in Range II

LeetCode Link:
https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/

Difficulty: Medium

Topics:
Dynamic Programming, Digit DP, Math

Approach:
Brute force works for small ranges but becomes
too slow for large values.

Use Digit DP:

1. Count waviness contributions while constructing
   numbers digit-by-digit.

2. Store:
   - previous two digits
   - whether number has started
   - current position
   - tight constraint

3. Whenever three consecutive digits are known:
   a b c

   digit b contributes 1 if:
   - b > a and b > c (peak)
   OR
   - b < a and b < c (valley)

4. DP returns:
   - count of valid numbers
   - total waviness

5. Answer:
   solve(num2) - solve(num1 - 1)

Time Complexity:
O(Length × States × 10)

≈ O(17 × 3 × 11 × 11 × 10)

Space Complexity:
O(17 × 3 × 11 × 11)
*/

class Solution {
public:

    using int64 = long long;

    struct Node {
        long long cnt;
        long long sum;
    };

    string s;

    Node dp[17][3][11][11];
    bool vis[17][3][11][11];

    Node dfs(
        int pos,
        bool tight,
        int lenState,
        int last2,
        int last1
    ) {

        if(pos == (int)s.size()) {
            return {1, 0};
        }

        if(!tight &&
           vis[pos][lenState][last2 + 1][last1 + 1]) {

            return dp[pos][lenState]
                     [last2 + 1]
                     [last1 + 1];
        }

        int limit =
            tight
            ? s[pos] - '0'
            : 9;

        Node res{0, 0};

        for(int d = 0; d <= limit; d++) {

            bool ntight =
                tight && (d == limit);

            if(lenState == 0) {

                // leading zeros
                if(d == 0) {

                    Node child =
                        dfs(
                            pos + 1,
                            ntight,
                            0,
                            -1,
                            -1
                        );

                    res.cnt += child.cnt;
                    res.sum += child.sum;
                }

                else {

                    Node child =
                        dfs(
                            pos + 1,
                            ntight,
                            1,
                            -1,
                            d
                        );

                    res.cnt += child.cnt;
                    res.sum += child.sum;
                }
            }

            else if(lenState == 1) {

                Node child =
                    dfs(
                        pos + 1,
                        ntight,
                        2,
                        last1,
                        d
                    );

                res.cnt += child.cnt;
                res.sum += child.sum;
            }

            else {

                int add = 0;

                if(
                    (last1 > last2 &&
                     last1 > d)

                    ||

                    (last1 < last2 &&
                     last1 < d)
                ) {
                    add = 1;
                }

                Node child =
                    dfs(
                        pos + 1,
                        ntight,
                        2,
                        last1,
                        d
                    );

                res.cnt += child.cnt;

                res.sum +=
                    child.sum +
                    1LL * add * child.cnt;
            }
        }

        if(!tight) {

            vis[pos][lenState]
               [last2 + 1]
               [last1 + 1] = true;

            dp[pos][lenState]
              [last2 + 1]
              [last1 + 1] = res;
        }

        return res;
    }

    long long solve(long long n) {

        if(n < 0) {
            return 0;
        }

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(
            0,
            true,
            0,
            -1,
            -1
        ).sum;
    }

    long long totalWaviness(
        long long num1,
        long long num2
    ) {

        return solve(num2)
             - solve(num1 - 1);
    }
};
