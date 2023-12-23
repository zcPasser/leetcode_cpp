#pragma once
#include "ListNode.h"
using namespace std;
class Solution {
private:
    void delDup(ListNode* head, ListNode* pre)
    {
        if (head == nullptr || head->next == nullptr)
            return ;
        if (head->next->val != head->val)
            delDup(head->next, head);
        else
        {
            ListNode* curr = head->next;
            while (curr != nullptr && curr->val == head->val)
                curr = curr->next;
            pre->next = curr;

            delDup(curr, pre);
        }
        return;

    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        delDup(head, dummyHead);

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

