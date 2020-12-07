#include <iostream>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int res;
        unordered_set<int> s;
        while (s.empty() || (s.count(n) == 0 && n != 1)) {
            s.insert(n);
            res = 0;
            while (n != 0) {
                res += (n%10)*(n%10);
                n = n/10;
            }
            n = res;
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

