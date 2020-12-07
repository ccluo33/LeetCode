#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int interval = 1;
        int n = lists.size();
        if (n == 0) {
            return NULL;
        } 
        while (interval < n) {
            for(int i = 0; i + interval < lists.size(); i += 2*interval) {
                ListNode *list1 = lists[i];
                ListNode *list2 = lists[i+interval];
                ListNode *res =  merge2Lists(list1, list2);
                lists[i] = res;
            }
            interval *= 2;
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode *list1, ListNode *list2) {
        ListNode *p = new ListNode(0), *head = p;
        ListNode *l1= list1, *l2 = list2;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }  else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        if (l1 == NULL) {
            p->next = l2;
        }
        if (l2 == NULL) {
            p->next = l1;
        }
        return head->next;
    }
};
// @lc code=end

