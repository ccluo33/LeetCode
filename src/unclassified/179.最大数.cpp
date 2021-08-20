#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const int & a, const int & b) {
        string aa = to_string(a);
        string bb = to_string(b);
        return aa+bb > bb+aa;
    }

    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) {
            return "0";
        }
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
// @lc code=end

