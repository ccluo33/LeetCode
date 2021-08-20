#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int k = i+1; k < arr.size(); k++) {
                int a = arr[i];
                int b = 0;
                for (int j = i+1; j <= k; j++) {
                    b = b^arr[j];
                }
                if (a == b) {
                    cnt++;
                }
                for (int j = i+2; j <= k; j++) {
                    a ^= arr[j];
                    b ^= arr[j];
                    if (a == b) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

