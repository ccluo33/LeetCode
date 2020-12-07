#include <iostream>
#include <cstdio>
using namespace std;

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int l = 0, r = 0, j = 0;
        int sFreq[26] = { 0 }, pFreq[26] = { 0 };
        for (int i = 0; i < p.size(); i++) {
            pFreq[p[i]-'a']++;
        }
        if (p.size() > s.size()) {
            return res;
        }
        sFreq[s[l]-'a']++;
        while (r < s.size()) {
            while (r-l+1 < p.size()) {
                r++;
                sFreq[s[r]-'a']++;
            }

            j = 0;
            while (j < 26) {
                if (pFreq[j] != sFreq[j]) {
                    break;
                }
                j++;
            }
            if (j == 26) {
                res.push_back(l);
            }
            sFreq[s[l]-'a']--;
            l++;
            r++;
            if (r < s.size()) {
                sFreq[s[r]-'a']++;
            }
        }
        return res;
    }
};
// @lc code=end

