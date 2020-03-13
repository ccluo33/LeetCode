#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* end = head;
        if (end == NULL) {
            return head;
        } else {
            ListNode* start = end;
            while(head->next != NULL) {
                ListNode* temp = new ListNode(head->next->val);
                temp->next = start;
                start = temp;
                head = head->next;
            }
            end->next = NULL;
            return start;
        }
    }
};
