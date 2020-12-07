#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int idx = -1;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i++) {
            if (idx == -1 || intervals[i][0] > res[idx][1]) {
                res.push_back(intervals[i]);
                idx++;
            } else {
                res[idx][1] = max(intervals[i][1], res[idx][1]);
            }
        }
        return res;
    }
};
// @lc code=end

