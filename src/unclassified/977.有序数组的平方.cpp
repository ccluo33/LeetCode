#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i]*A[i];
        }
        sort(A.begin(), A.end());
        return A;
    }
};

// @lc code=end

