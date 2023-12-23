#pragma once
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    int ans;
    int backtracking(TreeNode* root) {
        if (!root)
            return 2;
        int leftState = backtracking(root->left);
        int rightState = backtracking(root->right);
        if (leftState == 2 && rightState == 2)
            return 0;
        if (leftState == 0 || rightState == 0) {
            ans++;
            return 1;
        }
        if (leftState == 1 || rightState == 1)
            return 2;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        ans = 0;
        if (backtracking(root) == 0)
            ans++;
        return ans;
    }
};

