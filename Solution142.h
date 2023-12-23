#pragma once
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution142
{
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* p = head;
                while (slow != p) {
                    slow = slow->next;
                    p = p->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

