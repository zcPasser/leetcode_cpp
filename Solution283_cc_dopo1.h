#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numsSize = nums.size();
        int fast = 0, slow = 0;

        while (fast < numsSize) {
            if (nums[fast]) {
                swap(nums[fast], nums[slow]);
                ++slow;
            }
            ++fast;
        }
    }
};

