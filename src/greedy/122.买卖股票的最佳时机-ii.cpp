#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = prices.size()-1; i >= 0; i--) {
            if (i-1 >= 0) {
                prices[i] = prices[i] - prices[i-1];
            }
            if (i == 0) {
                prices[i] = 0;
            }
            if (prices[i] > 0) {
                res += prices[i];
            }
        }
        return res;
    }
};
// @lc code=end

