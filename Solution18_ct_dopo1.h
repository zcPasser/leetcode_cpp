#pragma once
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        using namespace std;
        vector<vector<int>> ans;
        int numsSize = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] > target && nums[i] >= 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < numsSize; ++j) {
                if (nums[j] > target - nums[i] && nums[j] >= 0)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                left = j + 1, right = numsSize - 1;
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                        --right;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                        ++left;
                    else {
                        ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        while (left < right && nums[right] == nums[right - 1])--right;
                        while (left < right && nums[left] == nums[left + 1])++left;
                        ++left, --right;
                    }
                }
            }
        }
        return ans;
    }
};

