#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0, n = s.size(), status = 0;
        vector<int> early_pos(1<<5, -1);
        early_pos[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                status ^= (1<<0);
            } else if (s[i] == 'e') {
                status ^= (1<<1);
            } else if (s[i] == 'i') {
                status ^= (1<<2);
            } else if (s[i] == 'o') {
                status ^= (1<<3);
            } else if (s[i] == 'u') {
                status ^= (1<<4);
            }
            if (early_pos[status] != -1) {
                res = max(res, i+1-early_pos[status]);
            } else {
                early_pos[status] = i+1;
            }
        }
        return res;
    }
};
// @lc code=end

