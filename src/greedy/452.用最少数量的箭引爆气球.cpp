#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        if (points.size() == 0) {
            return res;
        }
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        int pre = points[0][1];
        res++;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > pre) {
                res++;
                pre = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end

