#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isValid(s, l+1, r) || isValid(s, l, r-1);
            }
        }
        return true;
    }
    bool isValid(string s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }  
};
// @lc code=end

