#pragma once
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double level_sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* p = que.front();
                que.pop();
                if (p->left == nullptr)
                    que.push(p->left);
                if (p->right == nullptr)
                    que.push(p->right);
                level_sum += p->val;
            }
            ans.push_back(level_sum / size);
        }
        return ans;
    }
};

