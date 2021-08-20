#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, n = citations.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < citations.size(); i++) {
            int pos = lower_bound(citations.begin(), citations.end(), citations[i]) - citations.begin();
            if (citations[i] >= n - pos) {
                h = max(n - pos, h);
                break;
            } else {
                h = max(citations[i], h);
            }
        }
        return h;
    }
};
// @lc code=end

