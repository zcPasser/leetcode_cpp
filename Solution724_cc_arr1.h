#pragma once
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int numsSize = nums.size();
        //int ans = -1;
        int numsSum = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        for (int i = 0; i < numsSize; ++i) {
            preSum += nums[i];
            if (2 * preSum == numsSum + nums[i])
                return i;
        }
        return -1;
    }
};

