#pragma once
#include "ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* p = head, * pre = nullptr;
        while (p)
        {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return pre;
    }
};
