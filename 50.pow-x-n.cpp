#include <iostream>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == -1) {
            return 1/x;
        }
        double res = myPow(x, n >> 1);
        res *= res;
        if (n%2) {
            res = res*x;
        }
        return res;
    }
};
// @lc code=end

