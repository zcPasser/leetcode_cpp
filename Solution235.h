#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        if (root->val >= p->val && root->val <= q->val)
            return root;
        else if (root->val < p->val)
            return traversal(root->right, p, q);
        else
            return traversal(root->left, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val)
            return traversal(root, p, q);
        else
            return traversal(root, q, p);
    }
};

