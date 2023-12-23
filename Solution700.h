#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
    TreeNode* traversal(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;
        if (root->val > val)
            return traversal(root->left, val);
        return traversal(root->right, val);
    }
};

