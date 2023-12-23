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
        int cnt = 0;
        ListNode* p = head, * preQ = dummyHead, * q = head, * nextP = nullptr;
        while (q) {
            cnt++;
            nextP = q->next;
            if (cnt == k) {
                ListNode* d = p;
                // p ����һ���������Ϊ���νڵ�
                p = p->next;
                // β���뷽ʽʵ�� ��ת����
                while (p && p != nextP) {
                    ListNode* tmp = p->next;
                    p->next = preQ->next;
                    preQ->next = p;
                    p = tmp;
                }
                preQ = d;
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

