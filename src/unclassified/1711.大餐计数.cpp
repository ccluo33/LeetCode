#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1711 lang=cpp
 *
 * [1711] 大餐计数
 */

// @lc code=start
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1000000007;
        map<int, int> mp;
        int res = 0;
        for (int val: deliciousness) {
            int twoPower = 1;
            for (int i = 0; i <= 21; i++) {
                if (twoPower - val >= 0 && mp.find(twoPower - val) != mp.end()) {
                    res = (res + mp[twoPower - val]) % MOD; 
                }
                twoPower = twoPower * 2;
            }
            mp[val]++;
        }
        return res;
    }
};
// @lc code=end

