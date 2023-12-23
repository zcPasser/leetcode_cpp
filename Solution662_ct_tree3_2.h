#pragma once
#include "TreeNode.h"
#include <unordered_map>
using namespace std;
class Solution {
private:
    int ans = 0;
    // 维护 每一层 最左节点 编号（位置信息）
    unordered_map<int, int> levelNodeUomp;
    void dfs(TreeNode* root, int idx, int depth)
    {
        // 判断 depth层 最左节点，更新 levelNodeUomp
        if (levelNodeUomp.find(depth) == levelNodeUomp.end())
        {
            levelNodeUomp[depth] = idx;
        }

        // 更新 ans, 当前
        ans = max(ans, idx - levelNodeUomp[depth] + 1);
        
        // 重编号,0 开始
        idx = idx - levelNodeUomp[depth];

        // 递归
        if (root->left)
            dfs(root->left, idx << 1, depth + 1);
        if (root->right)
            dfs(root->right, idx << 1 | 1, depth + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
