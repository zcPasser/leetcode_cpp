#pragma once
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            TreeNode* p;
            while (size > 0) {
                size--;
                p = que.front();
                que.pop();
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
                if (size == 0)
                    ans.push_back(p->val);
            }
        }
        return ans;
    }
};

