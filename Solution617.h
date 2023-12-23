#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traversal(root1, root2);
    }
    TreeNode* traversal(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;
        if (root1 && !root2)
            return root1;
        if (!root1 && root2)
            return root2;
        TreeNode* root = new TreeNode();
        root->val = root1->val + root2->val;
        root->left = traversal(root1->left, root2->left);
        root->right = traversal(root1->right, root2->right);
        return root;
    }
};
