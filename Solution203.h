#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution203
{
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy_head = new ListNode();
		dummy_head->next = head;
		ListNode* p = dummy_head->next;
		ListNode* last = dummy_head;
		while (p){
			if (p->val == val) {
				last->next = p->next;
			}
			else {
				last = p;
			}
			p = last->next;
		}
		head = dummy_head->next;
		delete dummy_head, last;
		return head;
    }
};


