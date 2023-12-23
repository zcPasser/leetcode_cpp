#pragma once
#include<vector>
#include<set>
#include<limits>
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    int maxCnt = 0;
    TreeNode* pre = nullptr;
    int cnt = 0;
    vector<int> ans;
    void traversal(TreeNode* root) {
        if (!root)
            return;
        traversal(root->left);

        if (!pre) {
            cnt = 1;
        }
        else if (root->val == pre->val) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        pre = root;
        if (cnt == maxCnt) {
            ans.push_back(root->val);
        }else if(cnt > maxCnt) {
            ans.clear();
            maxCnt = cnt;
            ans.push_back(root->val);
        }

        traversal(root->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        
        ans.clear();
        traversal(root);
        
        return ans;
    }

};
