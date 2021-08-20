#include <iostream>
#include <cstring>
using namespace std;
/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m) {
            return false;
        }
        bool dp[n][n][n+1];     // dp[i][j][len]表示从字符串S中i开始长度为len的字符串是否能够变换为字符串T中j开始长度为len的字符串
        memset(dp, 0, sizeof(dp));
        // 处理单个字符的情况
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        // 枚举区间长度2~n
        for (int len = 2; len <= n; len++) {
            // 枚举S中的起点位置
            for (int i = 0; i <= n - len; i++) {
                // 枚举T中的起点位置
                for (int j = 0; j <= n - len; j++) {
                    // 枚举划分位置
                    for (int k = 1; k <= len - 1; k++) {
                        // 第一种情况: S1 -> T1, S2 -> T2
                        if (dp[i][j][k] && dp[i+k][j+k][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        // 第二种情况: S1 -> T2, S2 -> T1
                        // S1起点i, T2前面起点 j 加上前面的那段长度 len-k, S2起点i加上前面的那段长度k
                        if (dp[i][j+len-k][k] && dp[i+k][j][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
// @lc code=end

