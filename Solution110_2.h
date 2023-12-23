#pragma once
#include<stack>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            if (p) {
                stk.pop();
                if (p->right)
                    stk.push(p->right);
                stk.push(p);
                stk.push(nullptr);
                if (p->left)
                    stk.push(p->left);

            }
            else {
                stk.pop();
                p = stk.top();
                stk.pop();
                if (abs(getHeight(p->left) - getHeight(p->right)) > 1)
                    return false;
            }
        }
        return true;
    }
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        int depth = 0, ans = 0;
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            if (p) {
                stk.pop();
                stk.push(p);
                stk.push(nullptr);
                depth++;
                if (p->right)
                    stk.push(p->right);
                if (p->left)
                    stk.push(p->left);
            }
            else {
                stk.pop();
                p = stk.top();
                stk.pop();
                depth--;
            }
            ans = depth > ans ? depth : ans;
        }
        return ans;
    }
};

