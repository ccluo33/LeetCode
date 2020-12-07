#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> hash[26];
        vector<int> res;
        int l = 0, r = 0, pos = 0;
        for (int i = 0; i < S.size(); i++) {
            hash[S[i]-'a'].push_back(i);
        }
        while (r < S.size()) {
            pos = max(pos, hash[S[r]-'a'].back());
            while (r < pos) {
                r++;
                pos = max(pos, hash[S[r]-'a'].back());
            }
            if (r == pos) {
                res.push_back(r-l+1);
                r++;
                l = r;
            }
        }
        return res;
    }
};
// @lc code=end

