#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            // 求mid
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

