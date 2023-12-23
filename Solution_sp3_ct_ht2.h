#pragma once
#include<vector>
class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        int i = 0;
        while (i < numsSize) {
            if (nums[i] == i) {
                ++i;
                continue;
            }
            if (nums[i] == nums[nums[i]])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

