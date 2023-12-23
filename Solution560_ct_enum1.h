#pragma once
#include<vector>
class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        using namespace std;
        int numsSize = nums.size();
        int curSum = 0;
        int ans = 0;
        for (int left = 0; left < numsSize; ++left) {
            curSum = 0;
            for (int right = left; right >= 0; --right) {
                curSum += nums[right];
                if (curSum == k)
                    ++ans;
            }
        }
        return ans;
    }
};
