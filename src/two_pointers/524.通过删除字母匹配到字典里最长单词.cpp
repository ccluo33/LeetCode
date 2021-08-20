#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        string res = "";
        for (int i = 0; i < dictionary.size(); i++) {
            int word_index = 0, s_index = 0;
            while (word_index < dictionary[i].size() && s_index < s.size()) {
                if (dictionary[i][word_index] == s[s_index]) {
                    word_index++;
                }
                s_index++;
            }
            if (word_index == dictionary[i].size()) {
                res = dictionary[i];
                break;
            }
        }
        return res;
    };

    static bool cmp(string &a, string &b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        } else {
            return a < b;
        }
    }
};
// @lc code=end

