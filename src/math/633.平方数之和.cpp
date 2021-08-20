#include <iostream>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            if (sqrt(c*1.0-i*i*1.0) == int(sqrt(c*1.0-i*i*1.0))) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

