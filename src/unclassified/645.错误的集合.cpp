#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cnt(nums.size()+1, 0);
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i < cnt.size(); i++) {
            if (cnt[i] == 2) {
                res.push_back(i);
                break;
            }
        }
        for (int i = 1; i < cnt.size(); i++) {
            if (cnt[i] == 0) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
// @lc code=end

