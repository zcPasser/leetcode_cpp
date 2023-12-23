#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* p = head, * pre = nullptr, * tmp;
        while (p) {
            tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return pre;
    }
};
