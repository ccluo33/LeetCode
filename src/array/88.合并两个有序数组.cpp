#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int j = 0, k = 0, cnt = 0; 
        for (int i = 0; i < m; i++) {
            tmp.push_back(nums1[i]);
        }
        while (j < m && k < n) {
            if (tmp[j] <  nums2[k]) {
                nums1[cnt++] = tmp[j];
                j++;
            } else {
                nums1[cnt++] = nums2[k];
                k++;
            }
        }
        while (j < m) {
            nums1[cnt++] = tmp[j];
            j++;
        } 
        while (k < n) {
            nums1[cnt++] = nums2[k];
            k++;
        }
    }
};
// @lc code=end

