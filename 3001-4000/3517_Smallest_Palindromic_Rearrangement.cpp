/*
==================================================
Problem Number : 3517
Problem Name   : Smallest Palindromic Rearrangement
Difficulty     : Medium

Topics
- String
- Hash Table
- Greedy
- Counting

Pattern
- Frequency Counting
- Greedy Construction

Approach
- Count the frequency of each character.
- Build the first half of the palindrome by taking half of each character's frequency.
- If a character has an odd frequency, store it as the middle character.
- Create the second half by reversing the first half.
- Concatenate:
    firstHalf + middle + reverse(firstHalf)
- Return the resulting lexicographically smallest palindrome.

Time Complexity
O(n)

Space Complexity
O(1)

Learning
- Frequency arrays are efficient for lowercase English letters.
- Greedily placing smaller characters first ensures the lexicographically smallest result.
- A palindrome is completely determined by its first half and optional middle character.
- Reversing the first half constructs the second half automatically.

==================================================
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string firstHalf = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            firstHalf.append(freq[i] / 2, char('a' + i));

            if (freq[i] % 2) {
                middle = string(1, char('a' + i));
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};
