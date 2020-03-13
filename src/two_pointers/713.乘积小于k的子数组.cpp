#include <iostream>
#include <vector>
using namespace std;

/*
 * 双指针法，思路：对于一个乘积小于k的连续数组，那么它的所有子数组的乘积应该都小于k.
 * 如果该数组长度为n，可以得到它的连续子数组为1+2+...+n.
 * 实际在双指针操作时，对于数组[10, 5, 2, 6], k = 100， 会先拿到数组10满足条件，得到其子数组个数为1.
 * 然后拿到数组[10, 5]，其子数组个数为3，但是[10]前面已经算过了.
 * 为了避免重复，我们在拿到新的满足条件的数组时，只计算包含它的最后一个元素的子数组的个数.
 * 比如[10, 5]，我们只需要[5]和[10, 5]，很容易得到这样的子数组的个数就是原数组得长度: j-i+1.
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, prod = 1, res = 0;
        if (k == 0 || k == 1) {
            return 0;
        }
        for(int j = 0; j < nums.size(); j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};