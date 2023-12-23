#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize == 1)
            return nums[0];
        vector<int> dp(2, 0);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nsSize; i++) {
            dp[i%2] = dp[(i - 1)%2] < 0 ? nums[i] : dp[(i - 1)%2] + nums[i];
            ans = max(ans, dp[i%2]);
        }

        return ans;
    }
};

