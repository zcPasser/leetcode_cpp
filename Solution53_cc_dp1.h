#pragma once
#include<vector>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        int ans = nums[0], dpi = nums[0];
        for (int i = 1; i < numsSize; ++i) {
            dpi = max(dpi + nums[i], nums[i]);
            ans = max(ans, dpi);
        }
        return ans;
    }
};

