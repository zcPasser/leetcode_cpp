#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return traversal(root, pre);
    }
    bool traversal(TreeNode* root, TreeNode* & pre) {
        if (!root)
            return true;
        bool left = traversal(root->left, pre);
        if (pre && pre->val >= root->val)
            return false;            
        pre = root;
            
        bool right = traversal(root->right, pre);
        return left && right;
    }
};

