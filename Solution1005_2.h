#pragma once
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {return abs(a) > abs(b); });
        int numsSize = nums.size();
        int negativeIdx = -1;
        for (int i = 0; i < numsSize && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }     
        }
        if (k % 2 == 1) {
            nums[numsSize - 1] *= -1;
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

