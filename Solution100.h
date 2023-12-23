#pragma once
#include<stack>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if ((!p && q) || (p && !q) || (p->val != q->val))
            return false;
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        while (!stk.empty()) {
            TreeNode* r1 = stk.top();
            stk.pop();
            TreeNode* r2 = stk.top();
            stk.pop();
            if (!r1 && !r2)
                continue;
            if (!r1 || !r2 || (r1->val != r2->val))
                return false;
            stk.push(r1->left);
            stk.push(r2->left);
            stk.push(r1->right);
            stk.push(r2->right);
        }
        return true;
    }
};