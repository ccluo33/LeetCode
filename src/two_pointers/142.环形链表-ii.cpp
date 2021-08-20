#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode  *slow = head, *fast = head;
        do {
            if (!fast || fast->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end

