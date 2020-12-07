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
    int change;
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        change = 0;
        bool res = true;
        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                bool can_move = judgeNewi_j(s, i, j);
                if (can_move == false || change >= 2) {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }

    bool judgeNewi_j(string s, int& i, int& j) {
        int cnt = 1;
        if ((i+2*cnt-1) < j) {
            while ((i+2*cnt-1) < j) {
                if (s[i+cnt-1] == s[j-cnt] && s[i+cnt] == s[j-cnt+1]) {
                    cnt++;
                    if (!((i+2*cnt-1) < j)) {
                        i++;
                        change++;
                        break;
                    }
                } else if (s[i+cnt-1] == s[j-cnt]) {
                    j--;
                    change++;
                    break;
                } else if (s[i+cnt] == s[j-cnt+1]) {
                    i++;
                    change++;
                    break;
                } else {
                    return false;
                }
            }
        } else {
            i++;
            j--;
            change++;
        }
        return true;
    }
};
// @lc code=end