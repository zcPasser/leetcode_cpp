#pragma once
#include<vector>
#include"TreeNode.h"
class Solution {
private:
    std::vector<int> robTree(TreeNode* root) {
        if (root == nullptr)
            return { 0, 0 };
        std::vector<int> left = robTree(root->left);
        std::vector<int> right = robTree(root->right);
        int val1 = root->val + left[0] + right[0];
        int val2 = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        return { val2, val1 };
    }
public:
    int rob(TreeNode* root) {
        std::vector<int> ans = robTree(root);
        return std::max(ans[0], ans[1]);
    }
};

