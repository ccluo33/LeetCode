#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, j = numbers.size()-1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

