/*
Problem Number: 3518
Problem Name: Smallest Palindromic Rearrangement II

LeetCode Link:
https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/

Difficulty: Hard

Topics:
String, Greedy, Backtracking, Combinatorics,
Math, Counting

Approach:
We need to find the k-th lexicographically
smallest palindrome that can be formed
using all characters of the string.

Steps:

1. Count the frequency of every character.

2. Construct:
   - half[] = frequency / 2 for each letter.
   - middle character (if any).

3. Compute the total number of distinct
   permutations of the left half using
   multinomial coefficients.

4. If the number of possible palindromes
   is smaller than k, return an empty
   string.

5. Build the left half greedily:
   - Try every character from 'a' to 'z'.
   - Temporarily place it.
   - Count how many palindromes can be
     formed with the remaining characters.
   - If this count is at least k,
     keep the character.
   - Otherwise, subtract the count from k
     and try the next character.

6. Reverse the left half to obtain the
   right half.

7. Insert the middle character (if any)
   between the two halves.

Time Complexity:
O(26 × n²)

Space Complexity:
O(26)
*/

class Solution {
public:
    using int64 = long long;
    static constexpr int64 LIM = (1LL << 60);

    // nCr capped at LIM
    int64 comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= LIM) return LIM;
        }
        return (int64)res;
    }

    // Number of distinct permutations of a multiset
    int64 ways(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        int64 ans = 1;
        int left = rem;

        for (int x : cnt) {
            if (x == 0) continue;
            __int128 cur = (__int128)ans * comb(left, x);
            ans = (cur >= LIM ? LIM : (int64)cur);
            left -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = char('a' + i);
        }

        if (ways(half) < k) return "";

        int halfLen = s.size() / 2;
        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                int64 cnt = ways(half);

                if (cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= cnt;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;
        return left + right;
    }
};
