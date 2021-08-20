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
        // two pointers
        int j = nums.size()-1;
        for (int i = 0; i <= j; i++) {
            if (nums[i] == val) {
                swap(nums[i],nums[j]);
                i--;
                j--;
            }
        }
        // j的下一个元素是等于val的元素，所以返回的应该是j+1
        return j+1;
    }
};
// @lc code=end

