#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        int res = 0;
        if (N <= 2) 
            return N;
        if (N == 3) 
            return 6;
        res += N * (N-1) / (N-2) + (N-3);
        N = N - 4;
        while (N - 3 > 0) {
            res += (-N * (N-1) / (N-2) + (N-3));
            N = N - 4;
        }
        return res - clumsy(N);
    }
};
// @lc code=end

