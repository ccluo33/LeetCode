#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res1(2, -1);
        vector<int> res2;
        int lowerbound = findlowerbound(nums, target);
        int upperbound = findupperbound(nums, target);
        if (upperbound < lowerbound) {
            return res1;
        }
        res2.push_back(lowerbound);
        res2.push_back(upperbound);
        return res2;
    }

    int findlowerbound(vector<int> & nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int findupperbound(vector<int> & nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end

