#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = list1;
        ListNode* p1 = list1, * p2 = list2;
        ListNode* p = dummyHead;
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

