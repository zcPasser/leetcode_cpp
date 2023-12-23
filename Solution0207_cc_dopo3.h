#pragma once
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* p1 = headA, * p2 = headB;
        while (p1 != p2)
        {
            p1 = (p1) ? p1->next : headB;
            p2 = (p2) ? p2->next : headA;
        }

        return p1;
    }
};

