#pragma once
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int sizeLevel = que.size();
            ans = que.front()->val;
            for (int i = 0; i < sizeLevel; i++) {
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
