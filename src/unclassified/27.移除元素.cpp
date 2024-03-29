#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};
// @lc code=end

