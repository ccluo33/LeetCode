#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const pair<char, int>& lhs, const pair<char, int>& rhs) {  
        return lhs.second >= rhs.second;  
    }

    string frequencySort(string s) {
        string res = "";
        map<char, int> mp;
        for (auto& c: s) {
            mp[c]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end()); 
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].second; j++) {
                res += vec[i].first;
            }
        }
        return res;
    }
};
// @lc code=end

