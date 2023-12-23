#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead, * end = dummyHead, * q = head, * nextP = nullptr;
        int cnt = 0;
        while (end->next) {
            for (int i = 0; i < k && end; ++i)
                end = end->next;
            if (end == nullptr)
                break;
            ListNode* begin = pre->next;
            ListNode* nxt = end->next;
            //���� �ɻ�
            end->next = nullptr;
            //k�� ���ڷ�ת
            pre->next = reverse(begin);
            //��ǰ���ĩβ ���ӵ���һ��
            begin->next = nxt;
            //��һ���dummyHead
            pre = begin;

            end = pre;
        }
        return dummyHead->next;
    }
};

