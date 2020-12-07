#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = i + nums[i];
            ans = max(nums[i-1], ans);
            if (ans < i) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

