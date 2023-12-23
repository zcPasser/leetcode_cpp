#pragma once
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode():val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		traversal(root, ans);
		return ans;
	}
	void traversal(TreeNode* root, vector<int>& ans) {
		if (root == nullptr) {
			return;
		}
		ans.push_back(root->val);
		traversal(root->left, ans);
		traversal(root->right, ans);
	}
};

