#pragma once
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head, * slow = head;
        while (true)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            if (fast == slow)
                break;
        }
        ListNode* p = head;
        while (p != slow)
        {
            p = p->next;
            slow = slow->next;
        }

        return slow;
    }
};

