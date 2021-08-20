#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int sum = 0, res = 0, temp = 0; 
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (sum < goal) {
                continue;
            }
            while (sum > goal && i < j) {
                sum -= nums[i];
                i++;
            }
            if (sum == goal) {
                res++;
            }
            temp = i;
            while (temp < j && nums[temp] == 0) {
                temp++;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

