#pragma once
#include<vector>
class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        vector<int> cnt(101, 0);
        for (const int& num : nums)
            ++cnt[num];
        for (int i = 1; i < 101; ++i)
            cnt[i] += cnt[i - 1];
        vector<int> ans(numsSize, 0);
        for (int i = 0; i < numsSize; ++i)
            ans[i] = nums[i] == 0 ? 0 : cnt[nums[i] - 1];
        return ans;
    }
};

