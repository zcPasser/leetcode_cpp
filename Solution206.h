#pragma once
// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution206
{
public:
    ListNode* reverseList(ListNode* head) {
        if (! head || ! head -> next)
            return head;

        ListNode* p = head;
        ListNode* pre = nullptr;
        ListNode* tmp;
        while (p) {
            tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }

        return pre;
    }
};

