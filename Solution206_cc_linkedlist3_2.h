#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
private:
    ListNode* reverse(ListNode* cur, ListNode* pre) {
        if (!cur)
            return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(tmp, cur);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        return reverse(head, nullptr);
    }
};

