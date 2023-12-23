#pragma once
#include "TreeNode.h"
#include <unordered_map>
using namespace std;
class Solution {
private:
    int ans = 0;
    // ά�� ÿһ�� ����ڵ� ��ţ�λ����Ϣ��
    unordered_map<int, int> levelNodeUomp;
    void dfs(TreeNode* root, int idx, int depth)
    {
        // �ж� depth�� ����ڵ㣬���� levelNodeUomp
        if (levelNodeUomp.find(depth) == levelNodeUomp.end())
        {
            levelNodeUomp[depth] = idx;
        }

        // ���� ans, ��ǰ
        ans = max(ans, idx - levelNodeUomp[depth] + 1);
        
        // �ر��,0 ��ʼ
        idx = idx - levelNodeUomp[depth];

        // �ݹ�
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
