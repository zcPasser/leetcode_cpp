#pragma once
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            ans++;
            for (int i = 0; i < size; i++) {
                TreeNode* p = que.front();
                que.pop();
                if (!p->left && !p->right)
                    return ans;
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
        }
        return ans;
    }
};

