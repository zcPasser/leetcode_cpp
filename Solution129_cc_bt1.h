#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    void backtracking(TreeNode* root, int curSum, int &ans) {
        if (root) {
            curSum = curSum * 10 + root->val;
            if (!root->left && !root->right) {
                ans += curSum;
                return;
            }
            if (root->left)
                backtracking(root->left, curSum, ans);
            if (root->right)
                backtracking(root->right, curSum, ans);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        backtracking(root, 0, ans);
        return ans;
    }
};

