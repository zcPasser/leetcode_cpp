#pragma once
#include<vector>
class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        using namespace std;
        int sum = 0;
        for (int& num : nums)
            sum += num;
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0)
            return 0;
        int numsSize = nums.size(), neg = diff / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        
        for (int i = 0; i <= numsSize; ++i) {
            for (int j = neg; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[neg];
    }
};
