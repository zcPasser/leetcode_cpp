#pragma once
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        dfs(1, root, ans);
        return ans;
    }
    void dfs(int leveIdx, TreeNode* root, vector<vector<int>>& ans) {
        if (ans.size() < leveIdx)
            ans.push_back({});
        ans[leveIdx - 1].push_back(root->val);
        if (root->left)
            dfs(leveIdx + 1, root->left, ans);
        if (root->right)
            dfs(leveIdx + 1, root->right, ans);
    }
};
