#pragma once
#include<vector>
class Solution {
private:
    int robRange(std::vector<int>& nums, int begin, int end) {
        using namespace std;
        int dp0 = 0, dp1 = 0, dpi = 0;
        for (int i = begin; i <= end; ++i) {
            dpi = max(dp0 + nums[i], dp1);
            dp0 = dp1, dp1 = dpi;
        }
        return dp1;
    }
public:
    int rob(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize == 0)
            return 0;
        if (numsSize == 1)
            return nums[0];
        int ans1 = robRange(nums, 0, numsSize - 2);
        int ans2 = robRange(nums, 1, numsSize - 1);
        return max(ans1, ans2);
    }
};

