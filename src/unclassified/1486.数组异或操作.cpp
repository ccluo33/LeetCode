#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for (int i = start+2; i < start+2*n; i+=2) {
            res ^= i;
        }
        return res;
    }
};
// @lc code=end

