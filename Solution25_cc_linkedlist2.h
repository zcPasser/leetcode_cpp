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
            //避免 成环
            end->next = nullptr;
            //k个 组内反转
            pre->next = reverse(begin);
            //当前组的末尾 链接到下一组
            begin->next = nxt;
            //下一组的dummyHead
            pre = begin;

            end = pre;
        }
        return dummyHead->next;
    }
};

