/*
Problem Number: 3536
Problem Name: Maximum Product of Two Digits

LeetCode Link:
https://leetcode.com/problems/maximum-product-of-two-digits/

Difficulty: Easy

Topics:
Math, Digit Manipulation

Approach:
We need to find the two largest digits
in the given integer.

Steps:

1. Traverse all digits of the number.
2. Maintain:
      max1 = largest digit
      max2 = second largest digit
3. If the current digit is greater than
   or equal to max1:
      - Update max2 = max1
      - Update max1 = digit
4. Otherwise, if the digit is greater
   than max2, update max2.
5. Return:
      max1 × max2

Time Complexity:
O(d)

Space Complexity:
O(1)

where d is the number of digits.
*/

class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0; 
        int max2 = 0;

        while(n != 0){
            int digit = n % 10;
            n /= 10;

            if(digit >= max1){
                max2 = max1;
                max1 = digit;
            }
            else if(digit > max2){
                max2 = digit;
            }
        }
        return max1 * max2;
    }
};
