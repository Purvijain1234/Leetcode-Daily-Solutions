/*
Problem Number: 3763
Problem Name: Zig-Zag Arrays I

LeetCode Link:
https://leetcode.com/problems/zig-zag-arrays-i/

Difficulty: Hard

Topics:
Dynamic Programming, Prefix Sum, Math

Approach:
Let:

up[v]
= number of zig-zag arrays ending at value v
where the last relation is:

previous < current

down[v]
= number of zig-zag arrays ending at value v
where the last relation is:

previous > current

Initialization (length = 2):

up[v]
= count of smaller values

down[v]
= count of larger values

Transition:

To create an "up" state:

previous relation must be "down"

current value must be greater.

Using Prefix Sums:

nup[v]
=
Σ down[x]
for x < v

Similarly:

ndown[v]
=
Σ up[x]
for x > v

Use prefix and suffix sums to compute
all transitions efficiently.

Time Complexity:
O(n × m)

m = r - l + 1

Space Complexity:
O(m)
*/

class Solution {
public:

    static constexpr long long MOD =
        1000000007LL;

    int zigZagArrays(
        int n,
        int l,
        int r) {

        int m = r - l + 1;

        vector<long long>
            up(m + 1),
            down(m + 1);

        // Length = 2
        for(int v = 1; v <= m; v++) {

            up[v] = v - 1;

            down[v] = m - v;
        }

        if(n == 2) {

            long long ans = 0;

            for(int v = 1; v <= m; v++) {

                ans =
                    (ans +
                     up[v] +
                     down[v])
                    % MOD;
            }

            return (int)ans;
        }

        for(int len = 3;
            len <= n;
            len++) {

            vector<long long>
                nup(m + 1),
                ndown(m + 1);

            // Prefix sums
            long long pref = 0;

            for(int v = 1; v <= m; v++) {

                nup[v] = pref;

                pref =
                    (pref + down[v])
                    % MOD;
            }

            // Suffix sums
            long long suf = 0;

            for(int v = m;
                v >= 1;
                v--) {

                ndown[v] = suf;

                suf =
                    (suf + up[v])
                    % MOD;
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;

        for(int v = 1; v <= m; v++) {

            ans =
                (ans +
                 up[v] +
                 down[v])
                % MOD;
        }

        return (int)ans;
    }
};
