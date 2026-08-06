/*
Problem Number: 3345
Problem Name: Smallest Divisible Digit Product I

LeetCode Link:
https://leetcode.com/problems/smallest-divisible-digit-product-i/

Difficulty: Easy

Topics:
Math, Brute Force, Digit Manipulation

Approach:
Starting from n, check each number until
its digit product becomes divisible by t.

Steps:

1. Initialize the current number as n.

2. Compute the product of all digits of
   the current number.

3. If:
      product % t == 0
   return the current number.

4. Otherwise, increment the number and
   repeat the process.

Since the answer is guaranteed to exist,
the brute-force search eventually finds
the smallest valid number.

Time Complexity:
O(k × d)

where:
k = numbers checked
d = number of digits

Space Complexity:
O(1)
*/

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int x=n;
            int product = 1;
            while(x>0){
                product *= (x%10);
                x /= 10;
            }
            if(product % t == 0){
                return n;
            }
            n++;
        }
    }
};
