#pragma once
#include<algorithm>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        ans = traversal(root);
        return ans;
    }
    int traversal(TreeNode* root) {
        if (!root)
            return 0;
        int leftDpeth = traversal(root->left);
        int rightDpeth = traversal(root->right);
        if (root->left && !root->right)
            return 1 + leftDpeth;
        if (!root->left && root->right)
            return 1 + rightDpeth;
        return 1 + min(leftDpeth, rightDpeth);
    }
};

