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
                // ���ʽڵ�
                
                // ��� ���������ʽ��������Ϊ����ڵ� ����˳��׼����
                // ��ǰ ��-��-������ ����˳��Ϊ ��-��-��(��һ����������ӱ��)
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
                // ����ڵ�
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

