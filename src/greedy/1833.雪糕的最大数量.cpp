#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins - costs[i] >= 0) {
                res++;
                coins -= costs[i];
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

