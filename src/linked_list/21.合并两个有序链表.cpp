#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0), *p = l1, *q = l2;
        ListNode* end = head;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                end->next = p;
                end = p;
                p = p->next;
            } else {
                end->next = q;
                end = q;
                q = q->next;
            }
        }
        if (p != NULL) {
            end->next = p;
        }
        if (q != NULL) {
            end->next = q;
        }
        return head->next;
    }
};
// @lc code=end

