#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int minLen = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            minLen = min(minLen, int(strs[i].length()));
        }
        if (strs.size() != 0) {
            for (int i = 0; i < minLen; i++) {
                bool temp = true;
                for (int j = 0; j+1 < strs.size(); j++) {
                    if (strs[j][i] != strs[j+1][i]) {
                        temp = false;
                        break;
                    }
                }
                if (!temp) {
                    break;
                } else {
                    res += strs[0][i];
                }
            }
        }
        return res;
    }
};
// @lc code=end

