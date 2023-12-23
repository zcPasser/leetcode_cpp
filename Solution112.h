#pragma once
#include"TreeNode.h"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return traversal(root, targetSum, root->val);
    }
    bool traversal(TreeNode* root, int targetSum, int curSum) {
        if (!root->left && !root->right) {
            if (curSum == targetSum)
                return true;
            else
                return false;
        }
        bool leftAns = false, rightAns = false;
        if (root->left) {
            leftAns = traversal(root->left, targetSum, curSum + root->left->val);
        }
        if (root->right) {
            rightAns = traversal(root->right, targetSum, curSum + root->right->val);
        }
        return leftAns || rightAns;
    }
};

