#pragma once
#include"TreeNode.h"
#include<queue>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            ans++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* p = que.front();
                que.pop();
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
        }
        return ans;
    }
};

