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
        ListNode* pre = dummyHead, * p = head, * q = head->next;
        while (q) {
            if (p->val == q->val) {
                while (q && p->val == q->val) {
                    //p->next = q->next;
                    q = q->next;
                }
                pre->next = q;
                if (!q)
                    return dummyHead->next;
                //p = pre->next;
            }
            else {
                pre = pre->next;
                //p = p->next;
            }
            p = q;
            q = q->next;
        }
        return dummyHead->next;
    }
};


