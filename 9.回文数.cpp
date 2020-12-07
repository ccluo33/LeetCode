#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        bool res = false;
        if (x >= 0) {
            res = true;
            long long p = 0, temp = x;
            while (x > 0) {
                p = p*10 + (x % 10);
                x = x/10;
            }
            if (p != temp) {
                res = false;
            } 
        }
        return res;
    }
};
// @lc code=end

