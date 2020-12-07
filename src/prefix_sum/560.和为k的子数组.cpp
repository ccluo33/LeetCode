#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum;
        int res = 0;
        multimap<int, int> mp;
        multimap<int, int>::iterator iter;
        prefix_sum.push_back(0);
        mp.insert(pair<int, int>(0, 0));
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum.push_back(prefix_sum[i]+nums[i]);
            mp.insert(pair<int, int>(prefix_sum[i+1], i+1));
        }
        for (int i = 0; i < prefix_sum.size(); i++) {
            int rest = k + prefix_sum[i];
            int cnt = mp.count(rest);
	        iter = mp.find(rest);
            for (int j = 0; j < cnt; j++) {
                if (iter->second >= i+1) {
                    res++;
                }
                iter++;
            }
        }
        return res;
    }
};
// @lc code=end

