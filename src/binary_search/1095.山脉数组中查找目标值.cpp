#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int mid_point;
        findMountainTop(mountainArr, 0, n-1, mid_point);
        int res = -1;
        leftBinarySearchTarget(target, mountainArr, 0, mid_point, res);
        if (res == -1) {
            rightBinarySearchTarget(target, mountainArr, mid_point+1, n-1, res);
        }
        return res;
    }

    void findMountainTop(MountainArray &mountainArr, int left, int right, int& mid_point) {
        if (left > right) {
            return;
        } 
        int mid = left+(right-left)/2;
        int value = mountainArr.get(mid);
        if (mid-1 >= 0 &&  mid+1 < mountainArr.length() && mountainArr.get(mid-1) < value && value > mountainArr.get(mid+1)) {
            mid_point = mid;
            return;
        } else {
            if (mid-1 >= 0 && mountainArr.get(mid-1) < value) {
                findMountainTop(mountainArr, mid+1, right, mid_point);
            } else if (mid+1 < mountainArr.length() && mountainArr.get(mid+1) < value) {
                findMountainTop(mountainArr, left, mid, mid_point);
            } else {
                return;
            }
        }
    }

    void leftBinarySearchTarget(int target, MountainArray &mountainArr, int left, int right, int& res) {
        if (left == right) {
            if (mountainArr.get(left) == target) {
                res = left;
            }
            return;
        }
        if (left > right) {
            return;
        }
        int mid = left+(right-left)/2;
        int value = mountainArr.get(mid);
        if (value == target) {
            res = mid;
            return;
        } else if (value > target) {
            leftBinarySearchTarget(target, mountainArr, left, mid, res);
        } else {
            leftBinarySearchTarget(target, mountainArr, mid+1, right, res);   
        }
    }

    void rightBinarySearchTarget(int target, MountainArray &mountainArr, int left, int right, int& res) {
        if (left == right) {
            if (mountainArr.get(left) == target) {
                res = left;
            }
            return;
        }
        if (left > right) {
            return;
        }
        int mid = left+(right-left)/2;
        int value = mountainArr.get(mid);
        if (value == target) {
            res = mid;
            return;
        } else if (value > target) {
            rightBinarySearchTarget(target, mountainArr, mid+1, right, res);
        } else {
            rightBinarySearchTarget(target, mountainArr, left, mid, res);   
        }
    }
};
// @lc code=end

