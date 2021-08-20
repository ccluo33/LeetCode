#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (i+1 < nums.size() && nums[i] > nums[i+1]) {
                mid = i;
            }
        }
        int a = lower_bound(nums.begin(), nums.begin() + mid + 1, target) - nums.begin();
        int b = lower_bound(nums.begin() + mid + 1, nums.end(), target) - nums.begin();
        if (a < mid+1 && nums[a] == target) {
            res = a;
        } else if (b < nums.size() && nums[b] == target) {
            res = b;
        }
        return res;
    }
};
// @lc code=end

