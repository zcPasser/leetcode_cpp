#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* traversal(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        else if (root->val < key) {
            root->right = traversal(root->right, key);
        }
        else {
            root->left = traversal(root->left, key);
        }

        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traversal(root, key);
    }
};