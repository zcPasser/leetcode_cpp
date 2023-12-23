#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution27
{
public:
    int removeElement(vector<int>& nums, int val) {
        int idx1 = 0, idx2 = 0;
        while (idx2 < nums.size()) {
            if (nums[idx2] != val) {
                nums[idx1] = nums[idx2];
                idx1++;
            }
            idx2++;
        }
        return idx1;
    }
};

