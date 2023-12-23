#pragma once
#include<algorithm>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};

