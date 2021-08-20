#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1 && flowerbed[0] == 0) {
            n--;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (i == 0 && flowerbed.size() > 1 && flowerbed[i] == flowerbed[i+1]) {
                    flowerbed[i] = 1;
                    n--;
                }
                if (i == flowerbed.size()-1 && i-1 > 0 && flowerbed[i] == flowerbed[i-1]) {
                   flowerbed[i] = 1;
                   n--;
                }
                if (i > 0 && i < flowerbed.size()-1 && i-1 > 0 && flowerbed[i] == flowerbed[i-1] && flowerbed[i] == flowerbed[i+1]) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};
// @lc code=end

