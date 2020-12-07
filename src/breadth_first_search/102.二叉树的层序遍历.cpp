#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
            while (!q.empty()) {
                vector<int> temp;
                int len = q.size();
                for (int i = 0; i < len; i++) {
                    TreeNode *node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};
// @lc code=end

