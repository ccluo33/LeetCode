#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const pair<string, int> &a, const pair<string, int> &b) {  
        if (a.second != b.second) {
            return a.second > b.second; 
        } else {
            return a.first <= b.first;
        }
    }    

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordsFre;
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (wordsFre.find(words[i]) == wordsFre.end()) {
                wordsFre[words[i]] = 0;
            } else {
                wordsFre[words[i]]++;
            }
        }
        sort(wordsFre.begin(), wordsFre.end(), cmp);
        map<string, int>::iterator iter = wordsFre.begin();
        for (int i = 0; i < k; i++) {
            res.push_back(iter->first);
            iter++;
        }
        return res;
    }
};
// @lc code=end

