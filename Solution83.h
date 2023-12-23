#pragma once
#include"ListNode.h"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        using namespace std;
        if (!head || !head->next)
            return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p = head,*q=head->next;
        while (q) {
            if (p->val == q->val) {
                p->next = q->next;
                q = q->next;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
        return dummyHead->next;
    }
};
