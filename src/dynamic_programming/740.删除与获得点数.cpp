#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = 0;
        for (int val: nums) {
            maxValue = max(maxValue, val);
        }
        vector<int> sums(maxValue+1, 0);
        for (int val: nums) {
            sums[val] += val;
        }

        vector<int> dp(maxValue+1, 0);
        dp[0] = 0;
        dp[1] = sums[1];
        for (int i = 2; i <= maxValue; i++) {
            dp[i] = max(dp[i-2]+sums[i], dp[i-1]);
        }
        return dp[maxValue];
    }
};
// @lc code=end

