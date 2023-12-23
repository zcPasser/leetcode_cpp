#pragma once
#include<vector>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    TreeNode* traversal(vector<int>& inorder, int is, int ie,
        vector<int>& postorder, int ps, int pe) {
        if (is >= ie || ps >= pe)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pe - 1]);
        if ((pe - ps) == 1)
            return root;
        int idx = 0;
        for (idx = is; idx < ie; idx++) {
            if (inorder[idx] == root->val) {
                break;
            }
        }
        int lis = is;
        int lie = idx;
        int ris = idx + 1;
        int rie = ie;

        int lps = ps;
        int lpe = ps + idx - is;
        int rps = lpe;
        int rpe = pe - 1;
        
        root->left = traversal(inorder, lis, lie, postorder, lps, lpe);
        root->right = traversal(inorder, ris, rie, postorder, rps, rpe);
        return root;
    }
};

