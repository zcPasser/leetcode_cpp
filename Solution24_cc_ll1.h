#pragma once
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummyHead = new ListNode(), * p1, * p2, * p3;
        dummyHead->next = head;
        p1 = dummyHead, p2 = head, p3 = head->next;
        while (p2 && p3) {
            p2->next = p3->next;
            p3->next = p2;
            p1->next = p3;
            p1 = p2;
            p2 = p1->next;
            p3 = p2 == nullptr ? nullptr : p2->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

