#pragma once
#include"TreeNode.h"
class Solution {
public:
    int countNodes(TreeNode* root) {
        //int ans = 0;
        if (!root)
            return 0;
        TreeNode* left = root->left, * right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

