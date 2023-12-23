#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize < 2)
            return true;
        int furthestIdx = 0;
        for (int i = 0; i <= furthestIdx; i++) {
            furthestIdx = max(furthestIdx, i + nums[i]);
            if (furthestIdx >= (numsSize - 1))
                return true;
        }
        return false;
    }
};
