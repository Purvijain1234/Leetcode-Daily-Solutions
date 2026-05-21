/*
Problem Number: 0014
Problem Name: Longest Common Prefix

Difficulty: Easy

Topics:
String

Approach:
Start with the first string as prefix.

Compare the prefix with every string.
If current string does not start with prefix,
reduce the prefix size until it matches.

Time Complexity:
O(n * m)

n = number of strings
m = length of prefix

Space Complexity:
O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            string prefix = strs[0];

            // compare
            for(int i=0; i<strs.size(); i++){

                // reduce prefix until match
                while(strs[i].find(prefix) != 0){
                    prefix = prefix.substr(0, prefix.length() - 1);

                    // if prefix empty
                    if(prefix.empty()){
                        return "";
                    }
                }
            }
            return prefix;
    }
};
