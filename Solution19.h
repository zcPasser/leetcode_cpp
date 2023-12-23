#pragma once

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution19
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode();
        dummy_head->next = head;
        ListNode* slow = dummy_head, * fast = dummy_head, * pre = dummy_head;
        while (n-- && fast) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        head = dummy_head->next;
        delete dummy_head, slow;
        return head;
    }
};

