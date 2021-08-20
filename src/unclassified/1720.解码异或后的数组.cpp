#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            res.push_back(first^encoded[i]);
            first = first^encoded[i];
        }
        return res;
    }
};
// @lc code=end

