#include <iostream>
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
        long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return a;
        // if (x == 0) {
        //     return 0;
        // }
        // int l = 1, r = x, mid = 0;
        // while (l <= r) {
        //     mid = l + (r - l) / 2;
        //     if (mid == x / mid) {
        //         return mid;
        //     } else if (mid > x / mid) {
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        // return r;
    }
};
// @lc code=end

