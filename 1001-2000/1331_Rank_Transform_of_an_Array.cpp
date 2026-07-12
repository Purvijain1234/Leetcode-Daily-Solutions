/*
Problem Number: 1331
Problem Name: Rank Transform of an Array

LeetCode Link:
https://leetcode.com/problems/rank-transform-of-an-array/

Difficulty: Easy

Topics:
Array, Sorting, Hash Table

Approach:
The rank of a number is determined by its
position in the sorted unique array.

Steps:
1. Create a copy of the original array.
2. Sort the copied array.
3. Assign ranks to unique elements:
      smallest -> rank 1
      second smallest -> rank 2
      ...
4. Store the mapping:
      value -> rank
   using a Hash Map.
5. Replace every element in the original
   array with its corresponding rank.

Time Complexity:
O(n log n)

Space Complexity:
O(n)
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : temp) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        for (int &x : arr) {
            x = rank[x];
        }

        return arr;
    }
};
