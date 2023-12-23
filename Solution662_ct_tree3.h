#pragma once
#include "TreeNode.h"
#include <queue>
using namespace std;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode*, unsigned long long>> nodeQue;
        nodeQue.push({ root, 0 });
        unsigned long long ans = 1;
        TreeNode* node = nullptr;
        while (!nodeQue.empty())
        {
            int levelSize = nodeQue.size();
            for (int i = 0; i < levelSize; ++i)
            {
                node = nodeQue.front().first;
                unsigned long long idx = nodeQue.front().second;
                nodeQue.pop();
                if (node->left)
                    nodeQue.push({ node->left,2 * idx + 1 });
                    
                if (node->right)
                    nodeQue.push({ node->right, 2 * idx + 2 });
                    
            }

            // º«¬ºΩ·π˚
            if (nodeQue.size() > 1)
                ans = max(nodeQue.front().second - nodeQue.back().second + 1, ans);
            // ºÙ÷¶
            else if (nodeQue.size() == 1)
                nodeQue.front().second = 0;
            
        }
        return (int)ans;
    }
};
