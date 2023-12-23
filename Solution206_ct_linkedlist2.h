#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
//p = head, pre = nullptr;
//while (p) {
//    tm = p.next;
//    p.next = pre;
//    pre = p;
//    p = tmp;
//}
//return pre;
