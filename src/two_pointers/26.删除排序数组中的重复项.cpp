#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        if(nums.size() > 0) {
            len++;
        }
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[len-1]) {
                nums[len++] = nums[i];
            }
        }
        return len;     
    }
};