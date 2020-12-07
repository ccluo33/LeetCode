/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> pos;
        int n = nums.size(), res = 0, j = 0;
        for (int i = 0; i < n; i++) {
            pos.push_back(nums[i]+i);
        }
        if (n != 1) {
            while (j < n) {
                res++;
                int newj = 0, maxPos = 0;
                for (int k = j; k <= pos[j]; k++) {
                    if (k >= n-1) {
                        return res;
                    }
                    if (pos[k] >= n-1) {
                        if (k != j) {
                            res++;
                        }
                        return res;
                    }
                    if (pos[k] >= maxPos) {
                        maxPos = pos[k];
                        newj = k;
                    }
                }
                j = newj;
            }
        }
        return res;
    }
};
// @lc code=end

