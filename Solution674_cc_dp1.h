#pragma once
#include<vector>
class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        //vector<int> dp(numsSize, 1);
        int dp = 1;
        int ans = 1;
        for (int i = 1; i < numsSize; ++i) {
            if (nums[i] > nums[i - 1])
                dp += 1;
            else
                dp = 1;
            ans = max(ans, dp);
        }
        return ans;
    }
};
