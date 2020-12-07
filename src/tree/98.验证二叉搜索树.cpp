#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        vector<int> all_node;
        bool res = true;
        if (root) {
            InorderTravel(root, all_node);
        }
        if (all_node.size() > 1) {
            for (int i = 1; i < all_node.size(); i++) {
                if (all_node[i] <= all_node[i-1]) {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }

    void InorderTravel(TreeNode* root, vector<int>& all_node) {
        if (root) {
            InorderTravel(root->left, all_node);
            all_node.push_back(root->val);
            InorderTravel(root->right, all_node);
        }
    }
};
// @lc code=end

