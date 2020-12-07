#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
private:
    static bool cmp(int a, int b) {
        int a1sum = 0, b1sum = 0;
        int value = 1;
        for(int i = 0; i < 25; i++) {
            if (a & value) {
                a1sum++;
            }
            if (b & value) {
                b1sum++;
            }
            value = value*2;
        }
        if (a1sum == b1sum) {
            return a <= b;
        } else {
            return a1sum < b1sum;
        }
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
// @lc code=end

