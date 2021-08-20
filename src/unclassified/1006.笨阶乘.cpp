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
        int answer = 0, p = 0;
        int a[N];
        for (int i = 0; i < N; i++) {
            a[i] = N-i;
            if (i % 4 == 3) {
                answer += a[i];
            }
        }
        while (p+2 < N) {
            if (p == 0) {
                answer += a[p] * a[++p] / a[++p];
            } else {
                answer -= a[p] * a[++p] / a[++p];
            }
            p = p + 2;
        }
        if (p + 1 < N) {
            if (p == 0)
                answer += a[p] * a[++p];
            else
                answer -= a[p] * a[++p];
        } else if (p < N) {
             if (p == 0)
                answer += a[p];
            else
                answer -= a[p];
        }
        return answer;
    }
};
// @lc code=end

