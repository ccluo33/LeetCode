#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
    // vector<int> dailyTemperatures(vector<int>& T) {
    //     stack<int> s;
    //     vector<int> res;
    //     for (int i = T.size()-1; i >= 0; i--) {
    //         if (s.empty()) {
    //             res.push_back(0);
    //             s.push(T[i]);
    //         } else {
    //             if (T[i] < s.top()) {
    //                 res.push_back(1);
    //                 s.push(T[i]);
    //             } else {
    //                 int temp = 1;
    //                 while (T[i] >= s.top() && !s.empty()) {
    //                     temp++;
    //                     s.pop();
    //                 }
    //                 if (s.empty()) {
    //                     res.push_back(0);    
    //                 } else {
    //                     res.push_back(temp);
    //                     for (int j = 0; j < temp; j++) {
    //                         s.push(T[i]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

