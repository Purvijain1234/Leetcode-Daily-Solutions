/*
Problem Number: 3348
Problem Name: Smallest Divisible Digit Product II

LeetCode Link:
[https://leetcode.com/problems/smallest-number-with-given-digit-product/](https://leetcode.com/problems/smallest-number-with-given-digit-product/)

Difficulty: Hard

Topics:
Math, Dynamic Programming, Greedy

Approach:
We need to find the smallest number greater than or
equal to num whose digit product is divisible by t.

Steps:

1. Factorize t into prime factors 2, 3, 5 and 7.

   Every digit from 1 to 9 can only contribute
   these prime factors.

   If t contains any other prime factor,
   the answer is impossible, so return "-1".

2. Store the contribution of every digit:

   2 -> 2
   3 -> 3
   4 -> 2²
   5 -> 5
   6 -> 2 × 3
   7 -> 7
   8 -> 2³
   9 -> 3²

3. Use DP to find the minimum number of digits
   required to provide all required factors of
   2 and 3.

4. Handle factors 5 and 7 separately because
   digits 5 and 7 are the only digits that
   provide these factors.

5. First check whether num itself already has
   a digit product divisible by t.

6. If not, try to construct a number of the
   same length as num.

   Starting from the right side, increase one
   digit to the smallest possible larger digit.

   After fixing that digit, fill the remaining
   positions with the smallest possible digits
   that can satisfy the remaining prime factors.

7. If no valid number of the same length exists,
   construct the smallest valid number having
   more digits than num.

Time Complexity:
O(n × 9 × a × b)

Space Complexity:
O(n × a × b)

where:
n = length of num
a = required number of factors of 2
b = required number of factors of 3
*/

class Solution {
public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;

        while (t % 2 == 0) {
            req2++;
            t /= 2;
        }

        while (t % 3 == 0) {
            req3++;
            t /= 3;
        }

        while (t % 5 == 0) {
            req5++;
            t /= 5;
        }

        while (t % 7 == 0) {
            req7++;
            t /= 7;
        }

        // Product of digits can only contain primes 2,3,5,7.
        if (t != 1) return "-1";

        // factor[d] = number of (2,3,5,7) factors in digit d.
        int factor[10][4] = {};

        for (int d = 1; d <= 9; d++) {
            int x = d;

            while (x % 2 == 0) {
                factor[d][0]++;
                x /= 2;
            }

            while (x % 3 == 0) {
                factor[d][1]++;
                x /= 3;
            }

            while (x % 5 == 0) {
                factor[d][2]++;
                x /= 5;
            }

            while (x % 7 == 0) {
                factor[d][3]++;
                x /= 7;
            }
        }

        /*
            dp[i][j] = minimum number of digits required
            to get at least i factors of 2 and j factors of 3.

            Digits useful for (2,3):
            2 -> (1,0)
            3 -> (0,1)
            4 -> (2,0)
            6 -> (1,1)
            8 -> (3,0)
            9 -> (0,2)
        */

        const int INF = 1e9;

        vector<vector<int>> dp(req2 + 1,
                               vector<int>(req3 + 1, INF));

        dp[0][0] = 0;

        for (int i = 0; i <= req2; i++) {
            for (int j = 0; j <= req3; j++) {
                if (i == 0 && j == 0) continue;

                // Use digit 2
                if (i > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i - 1][j]);

                // Use digit 3
                if (j > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][j - 1]);

                // Use digit 4
                if (i >= 2)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i - 2][j]);
                else if (i > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[0][j]);

                // Use digit 6
                if (i > 0 && j > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i - 1][j - 1]);
                else if (i > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i - 1][0]);
                else if (j > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[0][j - 1]);

                // Use digit 8
                if (i >= 3)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i - 3][j]);
                else
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[0][j]);

                // Use digit 9
                if (j >= 2)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][j - 2]);
                else if (j > 0)
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][0]);
            }
        }

        auto minDigits = [&](int a, int b, int c, int d) {
            return c + d + dp[a][b];
        };

        auto possible = [&](int a, int b, int c, int d, int len) {
            return minDigits(a, b, c, d) <= len;
        };

        /*
            Construct lexicographically smallest valid string
            of exactly len digits.
        */
        auto build = [&](int len, int a, int b, int c, int d) {
            string res;
            res.reserve(len);

            for (int pos = 0; pos < len; pos++) {
                int left = len - pos - 1;

                for (int digit = 1; digit <= 9; digit++) {
                    int na = max(0, a - factor[digit][0]);
                    int nb = max(0, b - factor[digit][1]);
                    int nc = max(0, c - factor[digit][2]);
                    int nd = max(0, d - factor[digit][3]);

                    if (possible(na, nb, nc, nd, left)) {
                        res += char('0' + digit);

                        a = na;
                        b = nb;
                        c = nc;
                        d = nd;

                        break;
                    }
                }
            }

            return res;
        };

        int n = num.size();

        // prefix[i] = factors in num[0 ... i-1]
        vector<array<int, 4>> prefix(n + 1);
        prefix[0] = {0, 0, 0, 0};

        int firstZero = n;

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];

            if (num[i] == '0') {
                firstZero = min(firstZero, i);
                continue;
            }

            int digit = num[i] - '0';

            for (int j = 0; j < 4; j++)
                prefix[i + 1][j] += factor[digit][j];
        }

        // num itself.
        if (firstZero == n) {
            int a = max(0, req2 - prefix[n][0]);
            int b = max(0, req3 - prefix[n][1]);
            int c = max(0, req5 - prefix[n][2]);
            int d = max(0, req7 - prefix[n][3]);

            if (a == 0 && b == 0 && c == 0 && d == 0)
                return num;
        }

        /*
            Same length.

            Change the rightmost possible position.
            At that position, try the smallest larger digit.
        */
        for (int i = min(n - 1, firstZero); i >= 0; i--) {
            int current = num[i] - '0';

            for (int digit = current + 1; digit <= 9; digit++) {
                auto used = prefix[i];

                for (int j = 0; j < 4; j++)
                    used[j] += factor[digit][j];

                int a = max(0, req2 - used[0]);
                int b = max(0, req3 - used[1]);
                int c = max(0, req5 - used[2]);
                int d = max(0, req7 - used[3]);

                int left = n - i - 1;

                if (possible(a, b, c, d, left)) {
                    string ans = num.substr(0, i);

                    ans += char('0' + digit);

                    ans += build(left, a, b, c, d);

                    return ans;
                }
            }
        }

        /*
            No answer with n digits.

            Any zero-free number with more than n digits
            is automatically greater than num.
        */
        int len = max(
            n + 1,
            minDigits(req2, req3, req5, req7)
        );

        return build(len, req2, req3, req5, req7);
    }
};
