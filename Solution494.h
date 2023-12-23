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
        vector<vector<int>> dp(numsSize + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= numsSize; ++i) {
            for (int j = 0; j <= neg; ++j) {
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[numsSize][neg];
    }
};
