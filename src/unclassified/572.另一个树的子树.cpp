#include <iostream>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool equal = false;
        queue<TreeNode*> q;
        q.push(s);
        while(!q.empty()) {
            for (int i = 0; i < q.size(); i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val == t->val) {
                    equal = judgeEqual(node, t);
                }
                if (equal) {
                    break;
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            if (equal) {
                break;
            }
        }
        return equal;
    }

    bool judgeEqual(TreeNode* node1, TreeNode* node2) {
        bool res = false;
        if (node1 && node2 && node1->val == node2->val) {
            res = judgeEqual(node1->left, node2->left);
            if (res) {
                res = judgeEqual(node1->right, node2->right);
            }
        }
        if (node1 == NULL && node2 == NULL) {
            res = true;
        }
        return res;
    }
};
// @lc code=end

