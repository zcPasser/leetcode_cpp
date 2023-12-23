#pragma once
#include"TreeNode.h"
#include<vector>
using namespace std;
class Solution {
private:
    bool findP = false, findQ = false;
    vector<TreeNode*> pathP, pathQ;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (findP && findQ)
            return;

        if (!findP)
            pathP.push_back(root);
        if (!findQ)
            pathQ.push_back(root);

        if (root->val == p->val)
            findP = true;
        else if (root->val == q->val)
            findQ = true;

        if (root->left)
        {
            dfs(root->left, p, q);
            if (!findP)
                pathP.pop_back();
            if (!findQ)
                pathQ.pop_back();
        }
            
        if (root->right)
        {
            dfs(root->right, p, q);
            if (!findP)
                pathP.pop_back();
            if (!findQ)
                pathQ.pop_back();
        }
            
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        TreeNode* ans = nullptr;
        int idx = 0;
        int pathSize = min(pathP.size(), pathQ.size());
        while (idx <  pathSize)
        {
            if (pathP[idx] == pathQ[idx])
            {
                ans = pathP[idx];
                idx++;
            }
            else
                break;
        }
        return ans;
    }
};

