#pragma once
#include<vector>
#include<queue>
#include"ListNode.h"
using namespace std;
class Solution {
private:
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2)
    {
        if (h1 == nullptr)
            return h2;
        if (h2 == nullptr)
            return h1;
        ListNode* dummyHead = new ListNode(), * cur = dummyHead;;
        while (h1 != nullptr && h2 != nullptr)
        {
            if (h1->val < h2->val)
            {
                cur->next = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        cur->next = h1 != nullptr ? h1 : h2;
        // ×¢Òâ »ØÊÕ£¬new - delete
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p = nullptr, * q = nullptr;
        int listsSize = lists.size();
        
        queue<ListNode*> que;

        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i] != nullptr)
                que.push(lists[i]);
        }

        while (que.size() > 1)
        {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            que.push(mergeTwoList(p, q));
        }
        
        return que.size() == 1 ? que.front() : nullptr;
    }
};
