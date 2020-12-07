#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            res = max(res, (j-i)*min(height[i], height[j]));
            if (height[i] >= height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

