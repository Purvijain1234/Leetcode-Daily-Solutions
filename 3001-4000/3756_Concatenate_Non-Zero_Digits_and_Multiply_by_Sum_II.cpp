/*
Problem Number: 3756
Problem Name: Concatenate Non-Zero Digits and Multiply by Sum II

LeetCode Link:
https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/

Difficulty: Medium

Topics:
String, Prefix Sum, Binary Search, Math

Approach:
Multiple range queries are given.

For each query [l, r]:

1. Extract only the non-zero digits in
   the substring s[l...r].

2. Form the number x by concatenating
   these digits.

3. Compute the sum of these digits.

4. Return:
      x × sum (mod 1e9+7)

Optimization:

• Store the positions of all non-zero
  digits.

• Store their values.

• Build:
    - Prefix digit sum
    - Prefix concatenated value
    - Powers of 10

For every query:

• Binary Search to find the first and last
  non-zero digit inside the range.

• Compute x using prefix values.

• Compute digit sum using prefix sums.

Time Complexity:

Preprocessing:
O(n)

Each Query:
O(log n)

Overall:
O(n + q log n)

Space Complexity:
O(n)
*/

class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        // Store positions and values of non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        // powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix value and prefix digit sum
        vector<long long> prefVal(n + 1, 0), prefSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefVal[R + 1] -
                           prefVal[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};
