#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int numsSize = nums.size();
        if (numsSize == 3)
            return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int best = 1e7;
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target))
                best = cur;
        };
        for (int pa = 0; pa < numsSize - 2; pa++) {
            if (pa > 0 && nums[pa - 1] == nums[pa])
                continue;
            int pb = pa + 1, pc = numsSize - 1;
            while (pb < pc) {
                int curSum = nums[pa] + nums[pb] + nums[pc];
                if (curSum == target)
                    return target;
                update(curSum);
                if (curSum > target) {
                    int tmpPc = pc - 1;
                    while (pb < tmpPc && nums[tmpPc] == nums[pc])
                        tmpPc--;
                    pc = tmpPc;
                }
                else {
                    int tmpPb = pb + 1;
                    while (tmpPb < pc && nums[tmpPb] == nums[pb])
                        tmpPb++;
                    pb = tmpPb;
                }
            }
        }

        return best;
    }
};

