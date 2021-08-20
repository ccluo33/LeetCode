#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0, i = 0, j = 0, m = g.size(), n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < m && j < n) {
            if (s[j] >= g[i]) {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};
// @lc code=end

