#include <iostream>
#include <map>
using namespace std;

/*
 * @lc app=leetcode.cn id=992 lang=cpp
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> m;
        int begin = 0, end = 0, res = 0;
        while (end < A.size()) {
            m[A[end]]++;
            end++;
            while (m.size() > K) {     // 表内超过最大数据，缩小窗口
                if (m[A[begin]] > 1) {
                    m[A[begin]]--;
                } else {
                    m.erase(A[begin]);
                }
                begin++;
            }

            // 维持有K个不同的数。移动左边窗口
            int temp = begin;
            while (m.size() == K) {
                res++;
                if (m[A[temp]] > 1) {
                    m[A[temp]]--;
                } else {
                    m.erase(A[temp]);
                }
                temp++;
            } 

            // 恢复在移动左边窗口的时候字典中值得改变
            while (temp > begin) {
                m[A[temp-1]]++;
                temp--;
            }
        }
        return res;
    }
};

