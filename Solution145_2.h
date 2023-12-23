#pragma once
#include<vector>
#include<stack>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            if (p != nullptr) {
                stk.pop();
                stk.push(p);
                stk.push(nullptr);
                if (p->right)
                    stk.push(p->right);
                if (p->left)
                    stk.push(p->left);
            }
            else {
                stk.pop();
                p = stk.top();
                stk.pop();
                ans.push_back(p->val);
            }
        }
        return ans;
    }
};
