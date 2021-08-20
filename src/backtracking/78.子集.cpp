#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        back_tracking(nums, path, res, 0);
        return res;
    }

    void back_tracking(vector<int> & nums, vector<int> & path, vector<vector<int>> & res, int index) {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            back_tracking(nums, path, res, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

