#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
    int day[3] = {1, 7, 30};
    int memo[365] = { 0 }; // 备忘录memo[i]用来记录在完成前i-1的旅行计划时话费的钱数，从而实现回溯优化
    int minCost = INT_MAX;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 使用回溯法完成
        vector<int> interval;
        interval.push_back(1);
        for (int i = 1; i < days.size(); i++) {
            interval.push_back(days[i]-days[i-1]);
        }
        decideNext(interval, costs, 0, 0);
        return minCost;
    }

    void decideNext(vector<int>& interval, vector<int>& costs, int index, int cost) {
        if (minCost != INT_MAX && cost >= minCost) {
            return;
        }
        if (index == interval.size()) {
            minCost = min(cost, minCost);
            return;
        }
        if (memo[index] != 0 && cost >= memo[index]) {
            return;
        }
        memo[index] = cost;
        for (int i = 0; i < 3; i++) {
            int canDay = day[i]-1+interval[index];
            int old_index = index;
            cost += costs[i];
            while(canDay > 0 && index < interval.size()) {
                canDay -= interval[index];
                if (canDay >= 0) {
                    index++;
                }
            }
            decideNext(interval, costs, index, cost);
            cost -= costs[i];
            index = old_index;
        }
    }
};
// @lc code=end