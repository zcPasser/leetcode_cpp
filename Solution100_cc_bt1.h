#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    bool traversal(TreeNode* r1, TreeNode* r2) {
        if (r1 && r2) {
            if (r1->val != r2->val)
                return false;
            bool left = traversal(r1->left, r2->left);
            bool right = traversal(r1->right, r2->right);
            return left && right;
        }
        return r1 == nullptr && r2 == nullptr;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p, q);
    }
};

