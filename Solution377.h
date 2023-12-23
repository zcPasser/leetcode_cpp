#pragma once
#include<vector>
#include<limits>
class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        using namespace std;
        int numsSize = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j) {
            for (int i = 0; i < numsSize; ++i) {
                if (j - nums[i] >= 0 && INT_MAX - dp[j - nums[i]] >= dp[j])
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

