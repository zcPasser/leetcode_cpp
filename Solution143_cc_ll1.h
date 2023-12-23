#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr, * tmp = nullptr;
        while (head) {
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;

    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return ;
        ListNode* fast = head, * slow = head, * pre = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if (fast) {
            slow = slow->next;
        }
            
        slow = reverse(slow);
        fast = head;
        ListNode* tmp1 = nullptr, * tmp2 = nullptr;
        while (slow) {
            tmp1 = fast->next;
            fast->next = slow;
            tmp2 = slow->next;
            slow->next = tmp1;
            fast = tmp1;
            slow = tmp2;
        }
        fast->next = nullptr;
    }
};

