#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    // 层序遍历
    vector<vector<int>> subsets(vector<int>& nums) {
        int nsSize = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < nsSize; ++i)
        {
            int leveSize = ans.size();
            // 根据nums[i] 扩展
            for (int j = 0; j < leveSize; ++j)
            {
                path = ans[j];
                path.push_back(nums[i]);
                ans.push_back(path);
            }
        }
        return ans;
    }
};

