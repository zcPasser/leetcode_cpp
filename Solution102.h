#pragma once
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> level;
            while (size > 0) {
                size--;
                TreeNode* p = que.front();
                que.pop();
                level.push_back(p->val);
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

