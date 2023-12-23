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
#include<vector>
using namespace std;
class Solution {
private:
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, * pre = nullptr, * tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    void mergeList(ListNode* h1, ListNode* h2) {
        ListNode* cur1 = h1, * cur2 = h2;
        ListNode* tmp1 = nullptr, * tmp2 = nullptr;
        while (cur1 && cur2) {
            tmp1 = cur1->next;
            tmp2 = cur2->next;
            cur1->next = cur2;
            cur1 = tmp1;
            cur2->next = cur1;            
            cur2 = tmp2;
        }

    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode* midNode = getMidNode(head);
        ListNode* h1 = head;
        ListNode* h2 = midNode->next;
        midNode->next = nullptr;
        h2 = reverseList(h2);
        mergeList(h1, h2);
    }
};

