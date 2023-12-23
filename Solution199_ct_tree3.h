#pragma once
#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return{};
        vector<int> ans;
        
        queue<TreeNode*>que;
        que.push(root);
        while (!que.empty())
        {
            int levelSize = que.size();
            TreeNode* p = nullptr;
            for (int i = 0; i < levelSize; ++i)
            {
                p = que.front();
                que.pop();
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            if (p)
                ans.push_back(p->val);
        }
        return ans;
    }
};

