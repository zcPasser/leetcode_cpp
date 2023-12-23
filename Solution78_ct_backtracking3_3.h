#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void preOrder(const vector<int>& nums, int nsSize, int start, vector<int>& path, vector<vector<int>>& ans)
    {
        // 终止条件，叶子节点
        if (start >= nsSize)
        {
            ans.push_back(path);
            return;
        }
        // 选择 预处理
        path.push_back(nums[start]);
        // 左子树：选择
        preOrder(nums, nsSize, start + 1, path, ans);

        // 不选择 预处理
        path.pop_back();
        // 右子树：不选择
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

