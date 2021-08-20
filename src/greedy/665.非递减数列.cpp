#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool res = true;
        if (nums.size() == 1) {
            return  true;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if ((i+1 < nums.size() && nums[i+1] >= nums[i-1]) || i+1 >= nums.size()) {
                    nums[i] = nums[i-1];
                } else {
                    nums[i-1] = nums[i];
                }
                break;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] < 0) {
                res = false;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

