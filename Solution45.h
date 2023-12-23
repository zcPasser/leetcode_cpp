#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize < 2)
            return 0;
        int ans = 0;
        int curFurthestIdx = 0, nextFurthestIdx = 0;
        for (int i = 0; i < numsSize; i++) {
            nextFurthestIdx = max(nextFurthestIdx, nums[i] + i);
            if (i == curFurthestIdx) {
                if (curFurthestIdx < (numsSize - 1)) {
                    ans++;
                    curFurthestIdx = nextFurthestIdx;
                    if (curFurthestIdx >= (numsSize - 1))break;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
