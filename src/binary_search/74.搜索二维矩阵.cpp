#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int begin = 0, mid = 0, end = matrix.size()*matrix[0].size()-1;
        int m = matrix.size(), n = matrix[0].size();
        while (begin < end) {
            mid = (begin + end) / 2;
            if (matrix[mid/n][mid%n] < target) {
                begin = mid +1;
            } else {
                end = mid;
            }
        }
        return matrix[end/n][end%n] == target;
    }
};
// @lc code=end
   
