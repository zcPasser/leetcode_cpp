#pragma once
#include<vector>
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (end == begin)
            return nullptr;
        int mid = begin + (end - begin) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traversal(nums, begin, mid);
        node->right = traversal(nums, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
