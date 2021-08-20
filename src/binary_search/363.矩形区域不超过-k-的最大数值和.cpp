#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 * 枚举上下边界，更新每列元素的和，使用前缀和的方式存储，然后再使用set进行二分查找[lower_bound]sl(sl >= sr-k)
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {      // 枚举上边界
            vector<int> sum(n);
            for (int j = i; j < m; j++) {      // 枚举下边界
                for (int c = 0; c < n; c++) {
                    sum[c] += matrix[j][c];        // 更新每列元素的和
                }
                set<int> sumSet {0};
                int s = 0;
                for (int v: sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s-k);    // 找到最小的满足sl >= sr -k 的元素
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

