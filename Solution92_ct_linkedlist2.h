#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        int idx = 1;
        while (idx < left) {
            pre = pre->next;
            ++idx;
        }
        ListNode* cur = pre->next, * next;
        while (idx < right) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            ++idx;
        }

        return dummyHead->next;
    }
};


