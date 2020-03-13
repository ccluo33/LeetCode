#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution { 
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        int i = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (i <= j && sum >= s) {
                res = min(res, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        return (res == INT_MAX)? 0: res;
    }
};