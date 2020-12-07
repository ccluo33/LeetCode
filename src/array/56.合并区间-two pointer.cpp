#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty() || res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};
// @lc code=end

