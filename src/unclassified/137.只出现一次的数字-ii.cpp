#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        map <int, int>::iterator mp_iter;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp.insert(make_pair(nums[i], 1));
            } else {
                mp[nums[i]]++;
            }
        }
        for (mp_iter = mp.begin(); mp_iter != mp.end(); mp_iter++) {
            if (mp_iter->second == 1) {
                res = mp_iter->first;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

