#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int numsSize = nums.size();
        int left = 0, right = 0;
        int curSum = 0;
        int ans = numsSize + 1;
        while (right < numsSize) {
            curSum += nums[right];
            while (curSum >= target) {
                ans = min(ans, right - left + 1);
                curSum -= nums[left];
                ++left;
            }
            ++right;
        }
        return ans == numsSize + 1 ? 0 : ans;
    }
};
