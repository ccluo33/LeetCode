#include <iostream>
#include <vector>
#include <algorithm>
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
        int mid_point = 0;
        int res = -1;
        if (nums.size() == 1) {
            if (nums[0] == target) {
                res = 0;
            }
        } else if (nums.size() == 0) {
            res = -1;
        } else {
            search_point(0, nums.size()-1, nums, mid_point);
            if (mid_point == 0 && nums[0] < nums[1]) {
                res = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
                if (res == nums.size() || nums[res] != target) {
                    res = -1;
                }
            } else {
                res = lower_bound(nums.begin(), nums.begin()+mid_point+1, target) - nums.begin();
                if (res == nums.size() || nums[res] != target) {
                    res = lower_bound(nums.begin()+mid_point+1, nums.end(), target) - nums.begin();
                    if (res == nums.size() || nums[res] != target) {
                        res = -1;
                    }
                }
            }
        }
        return res;
    }

    void search_point(int left, int right, vector<int> & nums, int& mid_point) {
        if (left >= right) {
            return;
        }
        int mid = left + (right-left)/2;
        if (nums[mid] > nums[mid+1]) {
            mid_point = mid;
            return;
        } else {
            search_point(left, mid, nums, mid_point);
            search_point(mid+1, right, nums, mid_point);
        }
    }
};
// @lc code=end



