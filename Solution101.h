#pragma once
#include"TreeNode.h"
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return traversal(root->left, root->right);
    }
    bool traversal(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2)
            return true;
        if ((!r1 && r2) || (r1 && !r2) || (r1->val != r2->val))
            return false;
        bool outside = traversal(r1->left, r2->right);
        bool inside = traversal(r1->right, r2->left);
        return outside && inside;
    }
};
