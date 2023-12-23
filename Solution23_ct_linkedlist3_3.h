#pragma once
#include<vector>
#include<queue>
#include"ListNode.h"
using namespace std;
class Solution {
private:
    struct cmp
    {
        bool operator()(const ListNode* a, const ListNode* b) const
        {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> prioQue;

        int listsSize = lists.size();
        ListNode* dummyHead = new ListNode(), * cur = dummyHead, * p = nullptr;
        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i] != nullptr)
                prioQue.push(lists[i]);
        }

        while (!prioQue.empty())
        {
            p = prioQue.top();
            prioQue.pop();
            cur->next = p;
            cur = cur->next;
            if(p->next!=nullptr)
                prioQue.push(p->next);
        }
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
};
