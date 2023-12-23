#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize == 1)
            return nums[0];
        int left = 0, right = 0;
        int ans = nums[0], curSum = 0;
        int maxVal = nums[0];
        while (right < nsSize)
        {
            maxVal = max(maxVal, nums[right]);
            curSum += nums[right];
            right++;
            while (curSum <= 0 && left < right)
            {
                curSum -= nums[left]; 
                left++;
            }
            ans = max(curSum, ans);
        }
        if (maxVal < 0)
            ans = maxVal;
        return ans;
    }
};

