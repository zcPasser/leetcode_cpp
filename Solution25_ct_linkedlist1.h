#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* preQ = dummyHead, * p = head, * q = head, * nextP = nullptr;
        int cnt = 0;
        while (q) {
            cnt++;
            nextP = q->next;
            if (cnt == k) {
                ListNode* tmp = p;
                p = p->next;
                while (p && p != nextP) {
                    ListNode* tmp2 = p->next;
                    p->next = preQ->next;
                    preQ->next = p;
                    p = tmp2;
                }
                preQ = tmp;
                preQ->next = nextP;
                cnt = 0;
            }
            if (preQ->next == nextP)
                q = nextP;
            else
                q = q->next;
        }
        return dummyHead->next;
    }
};

