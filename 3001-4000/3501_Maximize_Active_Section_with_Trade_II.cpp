/*
Problem Number: 3501
Problem Name: Maximize Active Section with Trade II

LeetCode Link:
https://leetcode.com/problems/maximize-active-section-with-trade-ii/

Difficulty: Hard

Topics:
String, Greedy, Binary Search,
Sparse Table, Range Maximum Query (RMQ),
Run-Length Encoding (RLE)

Approach:
Unlike Trade I, multiple substring
queries are given.

Preprocessing:

1. Count the total number of active
   sections ('1's).

2. Compress every contiguous block of
   zeros into a group using
   Run-Length Encoding (RLE).

3. For every pair of adjacent zero
   groups, store their combined length.

4. Build a Sparse Table over these
   merged lengths to answer maximum
   range queries in O(1).

For every query:

1. Identify the zero groups intersecting
   the substring.

2. Handle fully contained zero groups
   using the Sparse Table.

3. Handle partial zero groups on the
   left and right boundaries.

4. Compute the maximum gain obtainable
   from one valid trade.

Time Complexity:

Preprocessing:
O(n log n)

Each Query:
O(log n)

Overall:
O((n + q) log n)

Space Complexity:
O(n log n)
*/

class Solution {
    struct Group {
        int start;
        int length;
    };

    class SparseTable {
        int n;
        vector<vector<int>> st;
        vector<int> lg;

    public:
        SparseTable(const vector<int>& nums) {
            n = nums.size();
            if (n == 0) return;
            int max_log = log2(n) + 1;
            st.assign(n, vector<int>(max_log, 0));
            lg.assign(n + 1, 0);

            for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
            for (int i = 0; i < n; i++) st[i][0] = nums[i];

            for (int j = 1; (1 << j) <= n; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        int query(int l, int r) const {
            if (l > r || l < 0 || r >= n) return 0;
            int k = lg[r - l + 1];
            return max(st[l][k], st[r - (1 << k) + 1][k]);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;

        vector<Group> zeroGroups;
        vector<int> zeroGroupIdx(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
                zeroGroupIdx[i] = zeroGroups.size() - 1;
            }
        }

        int m = zeroGroups.size();
        if (m < 2) {
            return vector<int>(queries.size(), totalOnes);
        }

        vector<int> adjacentMergeLengths(m - 1);
        for (int i = 0; i < m - 1; i++) {
            adjacentMergeLengths[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }

        SparseTable st(adjacentMergeLengths);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int activeSections = totalOnes;

            int gL = zeroGroupIdx[l];
            int gR = zeroGroupIdx[r];

            int startGroupIndex = (gL != -1) ? gL : -1;
            if (s[l] == '1') {
                auto it = lower_bound(zeroGroups.begin(), zeroGroups.end(), l, 
                    [](const Group& g, int val) { return g.start < val; });
                startGroupIndex = (it != zeroGroups.end()) ? distance(zeroGroups.begin(), it) : m;
            }

            int endGroupIndex = (gR != -1) ? gR : -1;
            if (s[r] == '1') {
                auto it = upper_bound(zeroGroups.begin(), zeroGroups.end(), r, 
                    [](int val, const Group& g) { return val < g.start; });
                endGroupIndex = (it != zeroGroups.begin()) ? distance(zeroGroups.begin(), prev(it)) : -1;
            }

            int fullStart = (s[l] == '0') ? startGroupIndex + 1 : startGroupIndex;
            int fullEnd = (s[r] == '0') ? endGroupIndex - 1 : endGroupIndex;

            if (fullStart <= fullEnd - 1) {
                activeSections = max(activeSections, totalOnes + st.query(fullStart, fullEnd - 1));
            }

            int leftLen = 0, rightLen = 0;
            if (s[l] == '0') {
                int gStart = zeroGroups[startGroupIndex].start;
                int gLen = zeroGroups[startGroupIndex].length;
                leftLen = gLen - (l - gStart);
            }
            if (s[r] == '0') {
                int gStart = zeroGroups[endGroupIndex].start;
                rightLen = r - gStart + 1;
            }

            if (s[l] == '0' && s[r] == '0' && startGroupIndex + 1 == endGroupIndex) {
                activeSections = max(activeSections, totalOnes + leftLen + rightLen);
            }
            if (s[l] == '0' && startGroupIndex + 1 <= fullEnd) {
                activeSections = max(activeSections, totalOnes + leftLen + zeroGroups[startGroupIndex + 1].length);
            }
            if (s[r] == '0' && fullStart <= endGroupIndex - 1) {
                activeSections = max(activeSections, totalOnes + rightLen + zeroGroups[endGroupIndex - 1].length);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};
