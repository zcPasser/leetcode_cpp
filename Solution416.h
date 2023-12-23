#pragma once
#include<vector>
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        using namespace std;
        int sum = 0;
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (sum % 2)
            return false;
        int target = sum / 2;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        if (dp[target] == target)
            return true;
        return false;
    }
};

