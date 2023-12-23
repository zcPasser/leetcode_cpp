#pragma once
#include"ListNode.h"
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* p1 = head, * p2 = head;
        while (p1 != nullptr && p2->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2)
                return true;
        }
        return false;
    }
};

