#pragma once
#include<queue>
#include"Node.h"
using namespace std;
class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            ans++;
            for (int i = 0; i < size; i++) {
                Node* p = que.front();
                que.pop();
                //p->children
                for (int j = 0; j < p->children.size(); j++) {
                    if (p->children[j])
                        que.push(p->children[j]);
                }
            }
        }
        return ans;
    }
};
