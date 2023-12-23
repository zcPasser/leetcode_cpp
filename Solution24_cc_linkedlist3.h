#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prev = dummyHead, * p1 = prev->next, * p2 = p1->next, * tmp = nullptr;
        while (p1 && p1->next) {
            p2 = p1->next;
            tmp = p2->next;
            prev->next = p2;
            p2->next = p1;
            p1->next = tmp;
            prev = p1;
            p1 = prev->next;   
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

