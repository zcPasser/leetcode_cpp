#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

//#include "SolutionSP29.h"
//#include "Solution93_ct_backtracking3.h"
//#include "Solution88_ct_array3.h"
//#include "Solution992_ct_hashtable1.h"
//#include "Solution165_ct_string3.h"
#include "Solution22_ct_tree3.h"
//#include"Solution0207_ct_dopo3.h"
//#include"Solution22_ct_dp3.h"
//#include "Solution1971_cc_graph1.h"
//#include"Solution28_cc_str3.h"
//#include"Solution15_cc_dopo3_2.h"
//#include"Solution33_ct_array1.h"
#include"Node.h"
#include"ListNode.h"
#include"TreeNode.h"
using namespace std;
using std::cout;

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}
	if (length == 0) {
		return "[]";
	}
	string ans;
	for (int idx = 0; idx < length; idx++) {
		int number = list[idx];
		ans += to_string(number) + ", ";
	}
	return "[" + ans.substr(0, ans.length() - 2) + "]";
}

ListNode* getList() {
	ListNode* p1 = new ListNode(0);
	p1->next = new ListNode(8);
	p1->next->next = new ListNode(6);
	ListNode* p2 = new ListNode(6);
	p2->next = new ListNode(7);
	p2->next->next = new ListNode(8);
	return p1;
}

long long quickMul(long long a, long long b) {
	long long ans = 0;
	while (b) {
		if (b & 1)
			ans += a;
		a <<= 1;
		b >>= 1;
	}
	return ans;
}

int main() {
	//quickMul(13, 27);
	Solution s = Solution();
	vector<vector<int>> nums = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
		//{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		//{".", ".", ".", ".", "8", ".", ".", "7", "9"}
	};
	//vector<vector<char>> nums2(9, vector<char>(9));
	//for (int i = 0; i < 9; ++i) {
	//	for (int j = 0; j < 9; ++j)
	//		nums2[i][j] = nums[i][j][0];
	//}
	//vector<int> nums1 = { 3,1,4,2 };
	//vector<vector<char>> nums1 = {
	//	{'A'}
	//};
	//vector<int> nums2 = { -4, -2, -3 };
	//vector<string> a = { "flower", "flow", "flight" };
	ListNode* p1 = new ListNode(4);
	p1->next = new ListNode(1);
	p1->next->next = new ListNode(8);
	p1->next->next->next = new ListNode(4);
	p1->next->next->next->next = new ListNode(5);

	ListNode* p2 = new ListNode(5);
	p2->next = new ListNode(0);
	p2->next->next = new ListNode(1);
	ListNode* c = p1->next->next;
	p2->next->next->next = c;
	c->next = new ListNode(4);
	c->next->next = new ListNode(5);
	//ListNode* p3 = new ListNode(2);
	//p3->next = new ListNode(6);

	//vector<ListNode*> nums1{ p1, p2, p3 };
	//TreeNode* root = new TreeNode(4);
	//root->left = new TreeNode(9);
	//root->left->left = new TreeNode(5);
	//root->left->right = new TreeNode(1);
	//root->right = new TreeNode(0);
	//vector<int> nums1 = { 5,2,3,1 };
	//vector<int> nums2 = { 1,0,0,1,1 };
	//string s1 = "aaaaaaaaaaaabbbbbcdd", s2 = "abcdd";
	//vector<int> a = { 0,0,1,1,1,1,2,3,3 };
	//vector<int> nums1 = { 4, 3, 2 },nums2={ 1, 3, 4, 2 }; 
	//string s1 = "cbaebabacd", s2 = "abc";
	//vector<string> ss = { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
	//vector<string> pizza = {
	//	"A..","AAA","..."
	//};
	//string v1 = "25525511135", v2 = "sad";
	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->left->right = new TreeNode(2);
	//root->right->left = new TreeNode(0);
	//root->right->right = new TreeNode(5);
	//root->left->right->left = new TreeNode(7);
	//root->left->right->right = new TreeNode(4);
	vector<int> n1 = { -1,0,1,2,-1,-4 }, n2 = { 2,5,6 };

	s.generateParenthesis(3);
	//cout<<;
	//[0, 8, 6, 5, 6, 8, 3, 5, 7]
	//[6, 7, 8, 0, 8, 5, 8, 9, 7]

	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(0);
	//root->right = new TreeNode(2);
	//s.convertBST(root);
	//cout << "0" << endl;
	//string out = integerVectorToString(s.sortedSquares(nums));
	//cout << out << endl;
	//string a = "cbaebabacd", p = "abc";
	//s.evalRPN(tokens);
	//cout << s.generateMatrix(3) << endl;
	//system("pause");
	return 0;
}