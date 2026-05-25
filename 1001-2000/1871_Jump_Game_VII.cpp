/*
Problem Number: 1871
Problem Name: Jump Game VII

Difficulty: Medium

Topics:
String, Dynamic Programming, Sliding Window, Prefix Sum

Approach:
Use a reachable array to track whether
a position can be reached.

For every reachable index:
mark all valid jump positions within
[minJump, maxJump].

Use farthest pointer to avoid revisiting
already processed indices.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        // Tracks reachable positions
        vector<bool> reachable(n, false);

        reachable[0] = true;

        // Prevent revisiting indices
        int farthest = 0;

        for(int i = 0; i < n; i++) {

            // Skip unreachable positions
            if(!reachable[i]) {
                continue;
            }

            // Valid jump range
            int start = max(i + minJump, farthest);

            int end = min(i + maxJump, n - 1);

            // Mark reachable positions
            for(int j = start; j <= end; j++) {

                if(s[j] == '0') {

                    reachable[j] = true;
                }
            }

            // Update farthest processed index
            farthest = end + 1;
        }

        return reachable[n - 1];
    }
};
