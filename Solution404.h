#pragma once
#include<queue>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        return traversal(root);
    }
    int traversal(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 0;
        int leftValue = 0;
        if (root->left && !root->left->left && !root->left->right)
            leftValue = root->left->val;
        else
            leftValue = traversal(root->left);
        int rightValue = traversal(root->right);
        return leftValue + rightValue;
    }
};

