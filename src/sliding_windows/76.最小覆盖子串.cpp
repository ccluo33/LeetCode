#include <iostream>
#include <cstdio>
using namespace std;

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int sFreq[64] = { 0 }, tFreq[64] = { 0 };
        for (int i = 0; i < t.size(); i++) {
            tFreq[t[i]-'A']++;
        }
        int l = 0, r = 0, i = 0;
        string res = "";
        if (s.size() < t.size()) {
            return res;
        }
        sFreq[s[l]-'A']++;
        while (r < s.size()) {
            while (r - l + 1 < t.size()) {
                r++;
                sFreq[s[r]-'A']++;
            }
            
            i = 0;
            while (i < 64) {
                if (sFreq[i] < tFreq[i]) {
                    break;
                }
                i++;
            }

            if (i == 64) {
                if (res == "" || res.size() > r-l+1) {
                    res = s.substr(l, r-l+1);
                }
                if (res.size() == t.size()) {
                    break;
                } else {
                    sFreq[s[l]-'A']--;
                    l++;
                }
            } else {
                r++;
                if (r < s.size()) {
                    sFreq[s[r]-'A']++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

