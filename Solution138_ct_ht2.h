#pragma once
#include<unordered_map>
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
private:
    std::unordered_map<Node*, Node*> cacheNode;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        return cacheNode[head];
    }
};

