#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        back_tracking(path, res, nums, 0);
        return res;
    }

    void back_tracking(vector<int> & path, vector<vector<int>> & res, vector<int> &nums, int index) {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            if ((i != index) && (nums[i-1] == nums[i])) {
                continue;
            } else {
                path.push_back(nums[i]);
                back_tracking(path, res, nums, i+1);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

