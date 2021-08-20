#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp1(n+1, 0);
        vector<int> dp2(n+1, 0);
        dp1[1] = nums[0];
        for (int i = 2; i < n; i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        dp2[2] = nums[1];
        for (int i = 3; i <= n; i++) {
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i-1]);
        }
        return max(dp1[n-1], dp2[n]);
    }
};
// @lc code=end

