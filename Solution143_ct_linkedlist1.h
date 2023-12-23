#pragma once
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include"ListNode.h"
#include<vector>
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        vector<ListNode*> vec;
        ListNode* cur = head;
        while (cur) {
            vec.emplace_back(cur);
            cur = cur->next;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            vec[left]->next = vec[right];
            ++left;
            vec[right]->next = vec[left];
            --right;

        }
        vec[left]->next = nullptr;
    }
};

