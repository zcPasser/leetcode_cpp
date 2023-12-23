#pragma once
#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode*> nodeStk;
        nodeStk.push(root);
        stack<int> depthStack;
        depthStack.push(0);
        int maxDepth = -1;
        while (!nodeStk.empty())
        {
            TreeNode* p = nodeStk.top();
            nodeStk.pop();
            int depth = depthStack.top();
            depthStack.pop();
            if (p)
            {
                // 访问节点
                
                // 结合 具体遍历方式，逆序处理，为处理节点 做好顺序准备。
                // 当前 根-右-左，所以 处理顺序为 左-右-根(下一个待处理，添加标记)
                if (p->left)
                {
                    nodeStk.push(p->left);
                    depthStack.push(depth + 1);
                }
                    
                if (p->right)
                {
                    nodeStk.push(p->right);
                    depthStack.push(depth + 1);
                }
                    
                nodeStk.push(p);
                depthStack.push(depth);
                nodeStk.push(nullptr);                
                depthStack.push(0);
            }
            else
            {
                // 处理节点
                p = nodeStk.top();                
                nodeStk.pop();
                depth = depthStack.top();
                depthStack.pop();
                if (depth == ans.size())
                {
                    ans.push_back(p->val);
                }
            }
        }
        return ans;
    }
};

