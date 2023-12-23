#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution26
{
public:
    int removeDuplicates(vector<int>& nums) {
        int idx1 = 0, idx2 = 1;
        while (idx2 < nums.size()) {
            if (nums[idx2] != nums[idx1]) {
                idx1 ++;
                nums[idx1] = nums[idx2];
            }
            idx2++;
        }
        return idx1 + 1;
    }
};

