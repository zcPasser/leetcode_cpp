#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize == 1)
            return nums[0];
        vector<int> dp(nsSize, 0);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nsSize; i++) {
            dp[i] = dp[i - 1] < 0 ? nums[i] : dp[i - 1] + nums[i];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

