#pragma once
#include<vector>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
    void traversal(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
    }
};
