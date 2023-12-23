#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize < 2)
            return;
        int i = nsSize - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i >= 0) {
            int j = nsSize - 1;
            while (i < j && nums[i] >= nums[j])
                --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};
