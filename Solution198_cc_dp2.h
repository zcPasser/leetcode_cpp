#pragma once
#include<vector>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize == 1)
            return nums[0];
        if (numsSize == 2)
            return max(nums[0], nums[1]);
        int dp0 = nums[0], dp1 = max(nums[0], nums[1]);
        int tmp = 0;
        for (int i = 2; i < numsSize; ++i) {
            tmp = dp1;
            dp1 = max(dp0 + nums[i], dp1);
            dp0 = tmp;
        }
        return dp1;
    }
};
