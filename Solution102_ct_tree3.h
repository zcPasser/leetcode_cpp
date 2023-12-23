#pragma once
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        vector<int> level;
        TreeNode* p = root;
        que.push(p);
        int leveSize = 0;
        while (!que.empty()) {
            leveSize = que.size();
            for (int i = 0; i < leveSize; i++) {
                p = que.front();
                level.push_back(p->val);
                que.pop();
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            ans.emplace_back(level);
            level.clear();
        }
        return ans;
    }
};
