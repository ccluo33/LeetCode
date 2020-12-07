#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = {0};
        int i = 0, j = 0, n = s.size(), res = 0;
        if (n > 0 ) {
            while (j < n) {
                hash[s[j]]++;
                j++;
                while (hash[s[j-1]] > 1) {
                    hash[s[i]]--;
                    i++;
                }
                res = max(res, j-i);
            }
        }
        return res;
    }
};
// @lc code=end

