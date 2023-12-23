#pragma once
#include<vector>
#include<unordered_set>
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(), * q = dummyHead, * cur = nullptr;
        unordered_set<ListNode*> unse;

        for (ListNode* list : lists)
            if (list != nullptr)
                unse.insert(list);

        while (!unse.empty())
        {
            int base = 10001;
            for (auto& list : unse)
            {
                if (list->val < base)
                {
                    base = list->val;
                    cur = list;                    
                }
            }
            q->next = cur;
            q = q->next;
            unse.erase(cur);
            if (cur->next != nullptr)
                unse.insert(cur->next);
        }
        return dummyHead->next;
    }
};
