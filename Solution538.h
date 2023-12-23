#pragma once
#include<stack>
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    int preVal = 0;
    void traversal(TreeNode* root) {
        if (!root)
            return ;
        traversal(root->right);
        root->val += preVal;
        preVal = root->val;
        traversal(root->left);
        return ;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        //int sum = sumBST(root);
        preVal = 0;
        traversal(root);
        return root;
    }
};