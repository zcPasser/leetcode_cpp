#pragma once
#include"TreeNode.h"
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        else
            return 0;
        TreeNode* node;
        stack<int> curSum;
        curSum.push(0);
        int ans = 0, sum = 0;
        while (!stk.empty()) {
            node = stk.top();
            if (node != nullptr) {
                stk.pop();
                //curSum.pop();
                if (node->right) {
                    stk.push(node->right);
                    //curSum.push(0);
                }
                    
                if (node->left) {
                    stk.push(node->left);
                    //curSum.push(0);
                }
                stk.push(node);
                stk.push(nullptr);
            }
            else {
                stk.pop();
                //curSum.pop();
                node = stk.top();
                stk.pop();
                sum = curSum.top();
                curSum.pop();
                curSum.push(sum * 10 + node->val);
                if (!node->left && !node->right) {
                    ans += curSum.top();
                    curSum.pop();
                }
            }
        }
        return ans;
    }
};

