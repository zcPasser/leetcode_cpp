#pragma once
#include<algorithm>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        invertTree(root->left);
        swap(root->left, root->right);
        invertTree(root->right);
        return root;
    }
    
};

