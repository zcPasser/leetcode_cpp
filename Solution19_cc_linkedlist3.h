#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p1 = dummyHead, * p2 = dummyHead,*prev=dummyHead;
        while (n--) {
            p2 = p2->next;
        }
        p1 = dummyHead->next;
        while (p2->next) {
            p2 = p2->next;
            prev = p1;
            p1 = p1->next;
        }
        prev->next = p1->next;
        delete p1;
        return dummyHead->next;
    }
};

