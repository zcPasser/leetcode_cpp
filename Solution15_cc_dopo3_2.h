#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nsSize - 2; ++i)
        {
            // 组间去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 剪枝
            if (nums[i] > 0)
                continue;
            int left = i + 1, right = nsSize - 1;
            int target = 0 - nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                    --right;
                else if (nums[left] + nums[right] < target)
                    ++left;
                else
                {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    // 去重
                    while (left + 1 < right && nums[left] == nums[left + 1])
                        ++left;
                    ++left;
                    while (left < right - 1 && nums[right] == nums[right - 1])
                        --right;
                    --right;
                }
            }
        }
        return ans;
    }
};


