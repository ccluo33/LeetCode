#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int rabbits[1000] = {0 }, sum = 0;
        for (int i = 0; i < answers.size(); i++) {
            rabbits[answers[i]]++;
        }
        sum += rabbits[0];
        for (int i = 1; i < 1000; i++) {
            if (rabbits[i] != 0) {
                sum += ceil((rabbits[i]*1.0)/((i+1)*1.0))*(i+1);
            }
        }
        return sum;
    }
};
// @lc code=end

