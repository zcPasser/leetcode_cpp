#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    // 二进制数模拟
    vector<vector<int>> subsets(vector<int>& nums) {
        int nsSize = nums.size();
        
        vector<vector<int>> ans;
        ans.push_back({});
        for (int bitVal = 0; bitVal < (1 << nsSize); ++bitVal)
        {
            vector<int> path;
            // 根据nums[i] 扩展
            for (int j = 0; j < nsSize; ++j)
                if((bitVal >> j) & 1)
                    path.push_back(nums[j]);                
            ans.push_back(path);
        }
        return ans;
    }
};

