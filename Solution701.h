#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) {
            root = node;
            return root;
        }
        TreeNode* p = root;
        TreeNode* pre;
        while (p) {
            pre = p;
            if (p->val < val)
                p = p->right;
            else
                p = p->left;
        }
        if (pre->val < val)
            pre->right = node;
        else
            pre->left = node;
        return root;
    }
};
