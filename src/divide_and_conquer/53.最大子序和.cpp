#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        return divide_conquer(nums, 0, n-1);
    }

    int divide_conquer(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = (left+right)/2;
        int leftMax = divide_conquer(nums, left, mid);
        int rightMax = divide_conquer(nums, mid+1, right);
        int crossMax = findCrossArray(nums, left, right);
        int result = max(leftMax, rightMax);
        result = max(result, crossMax);
        return result;
    }

    int findCrossArray(vector<int>& nums, int left, int right) {
        int mid = (left+right)/2;
        int leftSum = nums[mid], rightSum = INT16_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        sum = 0;
        for (int i = mid+1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }  
        return (leftSum + rightSum);      
    }
};
// @lc code=end

