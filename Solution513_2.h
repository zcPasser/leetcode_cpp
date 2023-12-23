#pragma once
#include<algorithm>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int maxDepth = -1;
        traversal(root, 1, maxDepth, ans);
        return ans;
    }
    void traversal(TreeNode* root, int depth, int& maxDepth, int& ans) {
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                ans = root->val;
            }
        }
        if (root->left) {
            traversal(root->left, depth + 1, maxDepth, ans);
        }
        if (root->right) {
            traversal(root->right, depth + 1, maxDepth, ans);
        }
    }
};

