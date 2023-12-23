#pragma once
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty()) {
            level++;
            int levelSize = que.size();
            ans += levelSize;
            int levelMaxSize = int(pow(2, level - 1));
            if (levelSize != levelMaxSize) {
                ans = levelMaxSize - 1 + levelSize;
                break;
            }

            for (int i = 0; i < levelSize; i++) {
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

