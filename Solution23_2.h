#pragma once
#include"ListNode.h"
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    struct comp {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, comp> prioQue;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto head : lists) {
            if(head)
                prioQue.push(head);
        }
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        while (!prioQue.empty()) {
            ListNode* node = prioQue.top();
            prioQue.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
                prioQue.push(node->next);
        }
        return dummyHead->next;
    }
};
