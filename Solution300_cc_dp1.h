#pragma once
#include<vector>
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        vector<int> dp(numsSize, 1);
        int ans = 0;
        for (int i = 1; i < numsSize; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

