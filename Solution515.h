#pragma once
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int levelMax = que.front()->val;
            while (size > 0) {
                size--;
                TreeNode* p = que.front();
                levelMax = max(levelMax, p->val);
                que.pop();
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
            }
            ans.push_back(levelMax);
        }
        return ans;
    }
};

