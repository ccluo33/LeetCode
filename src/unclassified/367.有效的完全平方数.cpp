#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i = 1; i*i <= num; i++) {
            if (i*i == num) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

