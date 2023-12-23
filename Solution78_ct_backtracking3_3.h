#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void preOrder(const vector<int>& nums, int nsSize, int start, vector<int>& path, vector<vector<int>>& ans)
    {
        // ��ֹ������Ҷ�ӽڵ�
        if (start >= nsSize)
        {
            ans.push_back(path);
            return;
        }
        // ѡ�� Ԥ����
        path.push_back(nums[start]);
        // ��������ѡ��
        preOrder(nums, nsSize, start + 1, path, ans);

        // ��ѡ�� Ԥ����
        path.pop_back();
        // ����������ѡ��
        preOrder(nums, nsSize, start + 1, path, ans);


    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int nsSize = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        preOrder(nums, nsSize, 0, path, ans);
        return ans;
    }
};

