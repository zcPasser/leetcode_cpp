#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p1 = dummyHead, * p2 = dummyHead;
        while (p1 && n > 0) {
            p1 = p1->next;
            --n;
        }
            
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2->next)
            p2->next = p2->next->next;
        return dummyHead->next;
    }
};

