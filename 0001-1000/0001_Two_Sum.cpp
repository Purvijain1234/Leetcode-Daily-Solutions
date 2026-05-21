/*
Problem Number: 0001
Problem Name: Two Sum

Difficulty: Easy

Topics:
Array, Hashing

Approach:
Brute Force using nested loops

Time Complexity:
O(n²)

Space Complexity:
O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
