#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int v): val(v), next(nullptr){}
	ListNode(int v, ListNode* n) : val(v), next(n) {}
};

#endif