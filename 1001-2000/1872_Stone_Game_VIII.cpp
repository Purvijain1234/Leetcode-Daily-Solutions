/*
Problem Number: 1872
Problem Name: Stone Game VIII

LeetCode Link:
https://leetcode.com/problems/stone-game-viii/

Difficulty: Hard

Topics:
Dynamic Programming, Game Theory, Prefix Sum

Approach:
Alice and Bob take turns merging stones into a single
stone. The goal is to maximize the final score difference.

Steps:

1. Compute the prefix sum of the stones.

   prefix[i] = stones[0] + stones[1] + ... + stones[i]

2. Start with:

   dp = prefix[n - 1]

   This represents the score difference when the entire
   array is considered as one prefix.

3. Iterate from right to left starting from n - 2 down to 1.

4. For every prefix[i], the current player has two choices:

   - Take the current prefix and let the opponent play:
     
       prefix[i] - dp

   - Keep the previously calculated best result:
     
       dp

5. Therefore, the transition is:

       dp = max(dp, prefix[i] - dp)

6. After processing all possible prefixes, dp represents
   the maximum score difference Alice can achieve.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = number of stones
*/
