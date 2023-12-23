#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* p1 = list1, * p2 = list2, * p;
        p = dummyHead;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;
        return dummyHead->next;
    }
};

