#pragma once
#include"ListNode.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int n = 0;
        ListNode* dummyHead = new ListNode(), * tail = nullptr, * p = nullptr;
        dummyHead->next = head, tail = dummyHead;
        while (tail->next) {
            ++n;
            tail = tail->next;
        }
        k %= n;
        if (k == 0)
            return head;
        int rest = n - k;
        p = dummyHead;
        for (int i = 0; i < rest; ++i) {
            p = p->next;
        }
        dummyHead->next = p->next;
        tail->next = head;
        p->next = nullptr;
        return dummyHead->next;
    }
};
