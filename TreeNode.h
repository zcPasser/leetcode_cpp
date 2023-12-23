#pragma once
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode * l, TreeNode * r):val(x),left(l),right(r){}
};