#pragma once
#include<limits.h>
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* pre;
    int ans=INT_MAX;
    void traversal(TreeNode* root) {
        if (!root)
            return;
        traversal(root->left);
        if (pre) {
            int tmp = root->val - pre->val;
            if (ans > tmp)
                ans = tmp;
        }
        pre = root;
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return ans;
    }
};
