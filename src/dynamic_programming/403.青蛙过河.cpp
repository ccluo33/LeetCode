#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][j]表示第i个石头是否可以跳j步
        vector<vector<bool>> dp(n, vector<bool>(n+1));
        dp[0][1] = true;
        for (int i = 1; i < n; i++) {
            bool flag = false;
            for (int j = i - 1; j >= 0; j--) {
                int diff = stones[i] - stones[j];
                if (diff > i) {
                    break;
                }
                // 对于石头j，它需要跳diff步
                if (dp[j][diff]) {
                    dp[i][diff-1] = true;
                    dp[i][diff] = true;
                    dp[i][diff+1] = true;
                    flag = true;
                }
            }
            if (i == n - 1 && !flag) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

