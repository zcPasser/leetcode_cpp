#pragma once
#include<vector>
#include<queue>
#include"Node.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> level;
            while (size > 0) {
                size--;
                Node* p = que.front();
                que.pop();
                level.push_back(p->val);
                for (Node* ch : p->children) {
                    que.push(ch);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
