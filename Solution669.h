#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* traversal(TreeNode* root, int low, int high) {
        if (!root)
            return root;
        if (root->val < low) {
            TreeNode* right = traversal(root->right, low, high);
            return right;
        }
        if (root->val > high) {
            TreeNode* left = traversal(root->left, low, high);
            return left;
        }
        root->left = traversal(root->left, low, high);
        root->right = traversal(root->right, low, high);
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traversal(root, low, high);
    }
};

