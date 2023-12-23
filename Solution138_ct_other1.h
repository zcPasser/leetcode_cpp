#pragma once
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        Node* p = head;
        Node* node = nullptr;
        while (p) {
            node = new Node(p->val);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        p = head;
        while (p != nullptr) {
            if (p->random != nullptr)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node* ans = head->next, * tmp;
        while (p != nullptr) {
            tmp = p->next;
            if (tmp != nullptr)
                p->next = tmp->next;
            p = tmp;
        }
        return ans;
    }
};


