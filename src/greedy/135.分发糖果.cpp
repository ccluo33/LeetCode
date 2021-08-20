#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies;
        for (int i = 0; i < ratings.size(); i++) {
            candies.push_back(1);
            if (i > 0 && ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

