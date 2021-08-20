#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[index2]*2, min(dp[index3]*3, dp[index5]*5));
            if (dp[i] == dp[index2]*2) {
                index2++;
            }
            if (dp[i] == dp[index3]*3) {
                index3++;
            }
            if (dp[i] == dp[index5]*5) {
                index5++;
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

