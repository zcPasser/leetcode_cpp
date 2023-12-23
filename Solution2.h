#pragma once
#include<math.h>
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, * p2 = l2;
        ListNode* head = p1, * last = nullptr;
        int sum = 0;
        int carry = 0;
        while (p1 && p2) {
            sum = p1->val + p2->val + carry;
            carry = sum / 10;
            p1->val = sum % 10;
            last = p1;
            p1 = p1->next, p2 = p2->next;
        }

        if (!p1) {
            p1 = p2;
            last->next = p1;
        }

        while (p1) {
            sum = p1->val + carry;
            carry = sum / 10;
            p1->val = sum % 10;
            last = p1;
            p1 = p1->next;
        }
        if (carry) {
            last->next = new ListNode(carry);
        }

        return head;
    }
};

