#pragma once
#include "ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* dummyHead = new ListNode(), * ppre = dummyHead, * pre = head, * curr = head->next;
        dummyHead->next = head;
        while (curr != nullptr)
        {
            if (pre->val != curr->val)
            {
                ppre = pre;
                pre = curr;
            }
            else
            {
                while (curr != nullptr && curr->val == pre->val)
                {
                    curr = curr->next;
                }
                ppre->next = curr;
                pre = curr;
            }
            if (curr != nullptr)
                curr = curr->next;
        }

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

