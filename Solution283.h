#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution283
{
public:
    void moveZeroes(vector<int>& nums) {
        int idx1 = 0, idx2 = 0;
        int len_nums = nums.size();
        while (idx2 < len_nums) {
            if (nums[idx2]) {
                swap(nums[idx1], nums[idx2]);
                idx1++;
            }
            idx2++;
        }
    }
};

