#include <iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        stack<ListNode*> s;
        while (true) {
            int cnt = 0;
            ListNode *temp = head;
            while (temp != NULL && cnt < k) {
                s.push(temp);
                temp = temp->next;
                cnt++;
            }

            if (cnt != k) {
                p->next = head;
                break;
            }
            while (!s.empty()) {
                p->next = s.top();
                s.pop();
                p = p->next; 
            }
            head = temp;
        }
        return res->next;
    }
};
// @lc code=end

