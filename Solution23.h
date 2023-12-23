#pragma once
#include"ListNode.h"
#include<vector>
using namespace std;
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (!h1)
            return h2;
        if (!h2)
            return h1;
        ListNode* dummyHead = new ListNode(), * p = dummyHead, * p1 = h1, * p2 = h2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return dummyHead->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

