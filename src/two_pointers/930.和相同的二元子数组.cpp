#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S) {
        int i = 0, res = 0, sum = 0, temp = 0;
        for (int j = 0; j < A.size(); j++) {
            sum += A[j];
            if (sum < S) {
                continue;
            }
            while (sum > S && i < j) {
                sum -= A[i++];
            }
            if (sum == S) {
                res++;
            }
            temp = i;
            while(temp < j && A[temp] == 0) {
                 temp++;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
