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
        long l = 0, r = (long)floor(sqrt(c));
        while (l <= r) {
            if (l*l + r*r == c) {
                return true;
            } else if (l*l + r*r >= c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};
// @lc code=end

