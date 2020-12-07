#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int dp[n+1][2];
        for (int i = 0; i < n+1; i++) {
            dp[i][0] = INT_MIN;
            dp[i][1] = INT_MIN;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                // 确定最大正数
                if (dp[i][0] > 0) {
                    dp[i+1][0] = dp[i][0]*nums[i];
                } else {
                    dp[i+1][0] = nums[i];
                }
                // 确定最大负数
                if (dp[i][1] < 0 && dp[i][1] != INT_MIN) {
                    dp[i+1][1] = dp[i][1]*nums[i];
                }
            } else {
                // 确定最大负数
                if (dp[i][0] > 0) {
                    dp[i+1][1] = dp[i][0]*nums[i];
                } else {
                    dp[i+1][1] = nums[i];
                }
                // 确定最大正数
                if (dp[i][1] < 0 && dp[i][1] != INT_MIN) {
                    dp[i+1][0] = dp[i][1]*nums[i];
                }
            }
            res = max(res, dp[i+1][0]);
            res = max(res, dp[i+1][1]);
        }
        return res;
    }
};
// @lc code=end

