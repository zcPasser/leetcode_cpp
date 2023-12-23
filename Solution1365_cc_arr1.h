#pragma once
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        int hash[101];
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        for (int i = numsSize - 1; i >= 0; --i)
            hash[sortedNums[i]] = i;
        vector<int> ans(numsSize, 0);
        for (int i = 0; i < numsSize; ++i)
            ans[i] = hash[nums[i]];
        return ans;
    }
};

