/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, i = 0, j = 0, ans = 0;
        int dp[50000+10] = { 0 };
        while (j < nums.size()) {
            if (nums[j] % 2 == 0 && j > 0) {
                dp[j] = dp[j-1];
            }
            if (nums[j] % 2) {
                ans++;
                if (ans == k) {
                    int temp = 1;
                    while (i < nums.size() && nums[i] % 2 == 0) {
                        temp++;
                        i++;
                    }
                    dp[j] = temp;
                    i++;
                    ans--;
                } else {
                    dp[j] = 0;
                }
            }
            j++;
        }
        for (int k = 0; k < 50000+10; k++) {
            res += dp[k];
        }
        return res;
    }
};
// @lc code=end

