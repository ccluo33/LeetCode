#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), res = 0, cnt = 0;
        if (n > 0) {
            int m = matrix[0].size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == '1') {
                        cnt = 1;
                        while(cnt+i < n && cnt+j < m) {
                            int temp = 0;
                            while (temp <= cnt) {
                                if (matrix[i+cnt][j+temp] == '0') {
                                    break;
                                }
                                if (matrix[i+temp][j+cnt] == '0') {
                                    break;
                                }
                                temp++;
                            }
                            if (temp == cnt+1) {
                                cnt++;
                            } else {
                                break;
                            }
                        }
                    }
                    res = max(res, cnt*cnt);
                }
            }
        }
        return res;
    }
};
// @lc code=end

