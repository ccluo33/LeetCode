#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode(0);
        ListNode* end = new ListNode(0);
        ListNode* s = start;
        ListNode* e = end;
        while (head != NULL) {
            if (head->val < x) {
                s = s->next = head;
            } else {
                e = e->next = head;
            }
            head = head->next;
        }
        e->next = NULL;
        s->next = end->next;
        return start->next;
    } 
};