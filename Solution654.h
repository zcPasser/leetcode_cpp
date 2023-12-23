#pragma once
#include<vector>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (end <= begin)
            return nullptr;
        int maxIdx = begin;
        for (int idx = begin; idx < end; idx++) {
            if (nums[maxIdx] < nums[idx]) {
                maxIdx = idx;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = traversal(nums, begin, maxIdx);
        root->right = traversal(nums, maxIdx + 1, end);
        return root;
    }
};
