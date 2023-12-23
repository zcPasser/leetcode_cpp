#pragma once
#include "ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(), * fast = dummyHead, * slow = dummyHead;
        dummyHead->next = head;
        while (n-- > 0)
            fast = fast->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

