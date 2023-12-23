#pragma once
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<TreeNode*> stk1, stk2;
        vector<vector<int>> ans;
        int flag = 0;
        stk1.push_back(root);
        TreeNode* p = nullptr;
        while (!stk1.empty() || !stk2.empty())
        {
            vector<int> level;
            if (flag % 2 == 0)
            {
                while (!stk1.empty())
                {
                    p = stk1.back();
                    level.push_back(p->val);
                    stk1.pop_back();
                    if (p->left)
                        stk2.push_back(p->left);
                    if (p->right)
                        stk2.push_back(p->right);
                }
            }
            else
            {
                while (!stk2.empty())
                {
                    p = stk2.back();
                    level.push_back(p->val);
                    stk2.pop_back();
                    if (p->right)
                        stk1.push_back(p->right);
                    if (p->left)
                        stk1.push_back(p->left);

                }
            }
            flag = (flag + 1) % 2;
            ans.push_back(level);
        }
        return ans;
    }
};
