#pragma once
#include<vector>
#include<string>
#include<iterator>
#include<sstream>
#include<algorithm>
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        vector<int> path;
        traversal(root, path, ans);
        return ans;
    }
    void traversal(TreeNode* root, vector<int>& path, vector<string>& ans) {
        if (!root->left && !root->right) {
            path.push_back(root->val);
            std::ostringstream oss;
            std::copy(path.begin(), path.end(), std::ostream_iterator<int>(oss, "->"));
            std::string onePath = oss.str();
            if (!onePath.empty())
                onePath.erase(onePath.length() - 2);
            ans.push_back(onePath);
            return;
        }
        path.push_back(root->val);
        if (root->left) {
            traversal(root->left, path, ans);
            path.pop_back();
        }
        if (root->right) {
            traversal(root->right, path, ans);
            path.pop_back();
        }
        
    }
};

