#pragma once
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int size_ = size;
            Node* last;
            while (size_ > 0) {
                Node* p = que.front();
                if (size_ < size)
                    last->next = p;
                last = p;
                que.pop();
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
                size_--;
            }
        }
        return root;
    }
};