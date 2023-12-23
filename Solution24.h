#pragma once
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, ListNode* n) : val(v), next(n) {}
};
class Solution24
{
public:
    ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* dummy_head = new ListNode();
		dummy_head->next = head;
		ListNode* p = head;
		ListNode* pre = dummy_head;
		while (p && p->next) {
			pre->next = p->next;
			p->next = p->next->next;
			pre->next->next = p;
			pre = p;
			p = p->next;
		}
		head = dummy_head->next;
		delete dummy_head;
		return head;
    }
};

