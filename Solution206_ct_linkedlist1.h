#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p1 = nullptr, *p2=head,*p3=head->next;
        while (p3) {
            p2->next = p1;
            p1 = p2, p2 = p3, p3 = p3->next;
        }
        p2->next = p1;
        return p2;
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
