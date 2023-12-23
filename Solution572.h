#pragma once
#include<stack>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool cur = compare(root, subRoot);
        if (cur)
            return true;
        if (root) {
            bool left = isSubtree(root->left, subRoot);
            if (left)
                return left;
            bool right = isSubtree(root->right, subRoot);
            if (right)
                return right;
        }           
            
        return false;;
    }

    bool compare(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2 || (r1->val != r2->val))
            return false;
        stack<TreeNode*> stk;
        stk.push(r1);
        stk.push(r2);
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            TreeNode* q = stk.top();
            stk.pop();
            if (!p && !q)
                continue;
            if (!p || !q || (p->val != q->val))
                return false;
            stk.push(p->left);
            stk.push(q->left);
            stk.push(p->right);
            stk.push(q->right);
        }
        return true;

    }
};

