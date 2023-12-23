#pragma once
#include<vector>
class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        using namespace std;
        int numsSize = nums.size();
        int left = 0, right = 0, ans = 0, tmpSum = 0, curSum = 0;
        while (right < numsSize) {
            curSum += nums[right];
            if (curSum == k)
                ++ans;
            tmpSum = curSum;
            while (left < right) {
                curSum -= nums[left];
                if (curSum == k)
                    ++ans;
                ++left;
            }
            curSum = tmpSum;
            left = 0;
            ++right;
        }
        return ans;
    }
};

