/*
Problem Number: 3614
Problem Name: Process String with Special Operations II

LeetCode Link:
https://leetcode.com/problems/process-string-with-special-operations-ii/

Difficulty: Hard

Topics:
String, Simulation, Reverse Thinking, Math

Approach:
Building the final string directly may be impossible
because '#' can double the string size exponentially.

Instead:

1. Compute the length of the string after each operation.
2. If k is outside the final length, return '.'.
3. Traverse operations backwards.
4. Map index k back to its origin:
   - Letter:
       If k points to the appended character,
       return it.
   - '*':
       Deleted the last character.
       Existing indices remain unchanged.
   - '#':
       result = prev + prev
       If k belongs to second half,
       move it to first half.
   - '%':
       result = reverse(prev)
       Map:
           k → len-1-k

5. Eventually reach the original character.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:

    char processStr(string s, long long k) {

        int n = s.size();

        const long long LIM =
            (long long)4e18;

        vector<long long>
            len(n + 1, 0);

        // Compute lengths
        for(int i = 0; i < n; i++) {

            char c = s[i];

            if('a' <= c &&
               c <= 'z') {

                len[i + 1] =
                    min(
                        LIM,
                        len[i] + 1
                    );
            }

            else if(c == '*') {

                len[i + 1] =
                    max(
                        0LL,
                        len[i] - 1
                    );
            }

            else if(c == '#') {

                len[i + 1] =
                    min(
                        LIM,
                        len[i] * 2
                    );
            }

            else { // %

                len[i + 1] =
                    len[i];
            }
        }

        if(k >= len[n]) {
            return '.';
        }

        // Reverse simulation
        for(int i = n - 1; i >= 0; i--) {

            char c = s[i];

            long long before =
                len[i];

            long long after =
                len[i + 1];

            // Letter appended
            if('a' <= c &&
               c <= 'z') {

                if(k == after - 1) {

                    return c;
                }
            }

            // Delete operation
            else if(c == '*') {

                continue;
            }

            // Duplicate
            else if(c == '#') {

                if(before > 0 &&
                   k >= before) {

                    k -= before;
                }
            }

            // Reverse
            else {

                if(before > 0) {

                    k =
                        before - 1 - k;
                }
            }
        }

        return '.';
    }
};
