#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (nums.size() > 2) {
            len = 2;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (!(nums[i] == nums[len-1] && nums[i] == nums[len-2])) {
                nums[len++] = nums[i];
            }
        }
        return len;
        
    }
};

