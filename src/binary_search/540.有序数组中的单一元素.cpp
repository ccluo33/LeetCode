#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, mid = 0;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            bool halves_odevity = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halves_odevity) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }

            } else if (nums[mid - 1] == nums[mid]) {
                if (halves_odevity) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};
// @lc code=end

