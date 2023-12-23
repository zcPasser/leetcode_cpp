#pragma once
#include<vector>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* traversal(vector<int>& preorder, int ps, int pe,
        vector<int>& inorder, int is, int ie) {
        if (is >= ie || ps >= pe)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
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

        int lps = ps + 1;
        int lpe = lps + idx - is;
        int rps = lpe;
        int rpe = pe;

        root->left = traversal(preorder, lps, lpe, inorder, lis, lie);
        root->right = traversal(preorder, rps, rpe, inorder, ris, rie);
        return root;
    }
};

