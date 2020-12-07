#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        vector<pair<int, int>> temp;
        for (int i = 0; i < points.size(); i++) {
            temp.push_back(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1], i));
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < K; i++) {
            int idx = temp[i].second;
            res.push_back(points[idx]);
        }
        return res;
    }
};
// @lc code=end

