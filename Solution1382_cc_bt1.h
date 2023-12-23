#pragma once
#include"TreeNode.h"
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root) {
            traversal(root->left);
            vec.push_back(root->val);
            traversal(root->right);
        }
    }
    TreeNode* getTree(const vector<int>& vals, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (right - left) / 2 + left;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = getTree(vals, left, mid - 1);
        root->right = getTree(vals, mid + 1, right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        traversal(root);
        return getTree(vec, 0, vec.size() - 1);
    }
};

