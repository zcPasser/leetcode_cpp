#pragma once
#include<vector>
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        int left = 0, right = numsSize - 1;
        int tmp = 0;
        for (int i = 0; i <= right; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                ++left;
            }
            if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
                if (nums[i] != 1)
                    --i;
            }
        }
    }
};

