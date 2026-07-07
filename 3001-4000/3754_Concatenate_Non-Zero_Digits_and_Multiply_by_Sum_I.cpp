/*
Problem Number: 3754
Problem Name: Concatenate Non-Zero Digits and Multiply by Sum I

LeetCode Link:
https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

Difficulty: Easy

Topics:
Math, String, Simulation

Approach:
1. Convert the integer to a string.
2. Traverse each digit:
   - Ignore '0'.
   - Append every non-zero digit to
     form a new number x.
   - Simultaneously compute the sum of
     these digits.
3. Return:
      x × sum

If the number contains only zeros,
then x = 0 and the answer is 0.

Time Complexity:
O(d)

Space Complexity:
O(d)

where d is the number of digits.
*/
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x =0;
        long long sum = 0;

        for(char c : s){
            if(c != '0'){
                int d = c - '0';
                x = x * 10 + d;
                sum += d;
            }
        }
        return x * sum;
    }
};
