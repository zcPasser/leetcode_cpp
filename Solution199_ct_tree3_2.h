#pragma once
#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    void dfs(TreeNode* root, int depth, vector<int>& ans)
    {
        if (depth == ans.size())
            ans.push_back(root->val);
        if (root->right)
            dfs(root->right, depth + 1, ans);
        if (root->left)
            dfs(root->left, depth + 1, ans);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return{};
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

