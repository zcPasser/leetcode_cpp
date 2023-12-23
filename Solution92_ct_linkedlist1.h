#pragma once
#include"ListNode.h"
using namespace std;
class Solution{
private:
    void reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head, * tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        //return 
    }
public:
    ListNode * reverseBetween(ListNode * head, int left, int right) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        int idx = 1;
        while (idx < left) {
            pre = pre->next;
            //p = p->next;
            ++idx;
        }
        ListNode* rightNode = pre;
        while (idx <= right) {
            rightNode = rightNode->next;
            ++idx;
        }
        ListNode* leftNode = pre->next;
        ListNode* cur = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseLinkedList(leftNode);

        pre->next = rightNode;
        leftNode->next = cur;

        return dummyHead->next;
    }
};

