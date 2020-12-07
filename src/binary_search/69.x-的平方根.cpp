#include <iostream>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x, res = 0;
        while (l <= r) {
            int mid = l+(r-l)/2;
            if ((long long)mid*mid <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end

