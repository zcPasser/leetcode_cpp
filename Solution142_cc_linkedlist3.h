#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        //�߽磺{0, 1}���ڵ�
        if (!head || !head->next)
            return nullptr;
        ListNode* p1 = head, * p2 = head;
        while (p1&&p1->next) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2)
                break;
        }
        //�޻���δ�ڻ���������
        if (p1 != p2)
            return nullptr;
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

