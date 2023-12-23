#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++)
            if (nums[i] <= 0)
                nums[i] = numsSize + 1;
        for (int i = 0; i < numsSize; i++) {
            int val = abs(nums[i]);
            if (val <= numsSize) {
                nums[val - 1] = -abs(nums[val - 1]);
            }
        }
        for (int i = 0; i < numsSize; i++)
            if (nums[i] > 0)
                return i + 1;
        return numsSize + 1;
    }
};

