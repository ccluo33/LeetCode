#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<TreeNode*, int>> q;
        if (root != NULL) {
            q.push(make_pair(root, 0));
            while (!q.empty()) {
                pair<TreeNode*, int> temp = q.front();
                q.pop();
                if (q.empty() || temp.second < q.front().second) {
                    result.push_back(temp.first->val);
                } 
                if (temp.first->left != NULL) {
                    q.push(make_pair(temp.first->left, temp.second+1));
                } 
                if (temp.first->right != NULL) {
                    q.push(make_pair(temp.first->right, temp.second+1));
                }
            }
        }
        return result;
    }
};
// @lc code=end

