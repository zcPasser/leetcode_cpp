#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || !root)
            return root;
        TreeNode* left = traversal(root->left, p, q);
        TreeNode* right = traversal(root->right, p, q);
        if (left && right)
            return root;
        else if (!left && right)
            return right;
        else if (left && !right)
            return left;
        else
            return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};
