#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, zerocnt = 0, res = 0;
        while (r < A.size()) {
            if (A[r] == 0) {
                zerocnt++;
            }
            r++;
            while (zerocnt > K) {
                if (A[l] == 0) {
                    zerocnt--;
                }
                l++;
            }
            res = max(res, r-l);
        }
        return res;
    }
};
// @lc code=end

