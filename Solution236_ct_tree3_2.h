#pragma once
#include"TreeNode.h"

using namespace std;
class Solution {
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);
        if (left && right)
            return root;
        
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return dfs(root, p, q);
    }
};

