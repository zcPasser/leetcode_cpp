#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prev = dummyHead, * p = head;
        while (p) {
            if (p->val == val)
                prev->next = p->next;
            else
                prev = p;
            p = p->next;
        }
        return dummyHead->next;
    }
};

