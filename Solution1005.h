#pragma once
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        int negativeIdx = -1;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] < 0)
                negativeIdx = i;
        }
        int restK = k;
        for (int i = 0; i <= negativeIdx && i < k; i++) {
            nums[i] = -nums[i];
            restK--;
        }
        if (restK > 0 && negativeIdx == (numsSize - 1) && restK % 2 == 1) {
            nums[negativeIdx] = -nums[negativeIdx];
        }
        else if (restK > 0 && nums[negativeIdx + 1] != 0 && restK % 2 == 1) {
            if(negativeIdx > -1 && nums[negativeIdx] < nums[negativeIdx + 1])
                nums[negativeIdx] = -nums[negativeIdx];
            else
                nums[negativeIdx + 1] = -nums[negativeIdx + 1];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

