#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vals;
        if (root) {
            in_order(root, vals);
            TreeNode* head = new TreeNode(vals[0]);
            TreeNode* p = head;
            for (int i = 1; i < vals.size(); i++) {
                TreeNode* q = new TreeNode(vals[i]);
                p->right = q;
                p = p->right;
            }
            return head;
        }
        return root;
    }

    void in_order(TreeNode* root, vector<int>& vals) {
        if (root->left) {
            in_order(root->left, vals);
        }
        vals.push_back(root->val);
        if (root->right) {
            in_order(root->right, vals);
        }        
    }
};
// @lc code=end

