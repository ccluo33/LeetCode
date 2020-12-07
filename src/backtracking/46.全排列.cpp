#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        for (int i = 1; i <= n; i++) {
            len = len * i;
        }
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> hashTable(n, 0);
        generateP(0, nums, hashTable, res, temp);
        return res;
    }

    void generateP(int index, vector<int>& nums, vector<bool>& hashTable, vector<vector<int>>& res, vector<int>& temp) {
        if (index == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable[i] == false) {
                temp.push_back(nums[i]);
                hashTable[i] = true;
                generateP(index+1, nums, hashTable, res, temp);
                hashTable[i] = false;
                temp.pop_back();
            }
        }
    }
};
// @lc code=end

