#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid = 0, min_value = 50001;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < min_value) {
                min_value = nums[mid];
            }
            if (nums[mid] == nums[start]) {
                start++;
            } else if (nums[mid] <= nums[end]) {
                end = mid - 1;
            } else {
                min_value = min(min_value, nums[start]);
                start = mid + 1;
            }
        }
        return min_value;
    }
};
// @lc code=end

