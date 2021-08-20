#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;                    // set使用红黑树存储元素，lower_bound使用二分查找，删除元素也很方便
        for (int i = 0; i < nums.size(); i++) {
            auto lb = st.lower_bound((long)nums[i] - t);     // 返回第一个>=(nums[i]-t)的迭代器
            if (lb != st.end() && *lb <= (long)nums[i] + t) return 1;
            st.insert(nums[i]);
            if (i >= k) st.erase(nums[i - k]);                // 删除前面的不在滑动窗口中的元素
        }
        return 0;
    }
};
// @lc code=end

