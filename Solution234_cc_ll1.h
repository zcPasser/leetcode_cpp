#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
private:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* pre = nullptr, * next = nullptr;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            slow = slow->next;
        slow = reverse(slow);
        fast = head;
        while (slow) {
            if (slow->val != fast->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

