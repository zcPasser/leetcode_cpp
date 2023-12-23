#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int nsSize = nums.size();
        int oddIdx = 1;
        for (int i = 0; i < nsSize; i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[oddIdx] % 2 == 1)
                    oddIdx += 2;
                swap(nums[i], nums[oddIdx]);
            }
        }
        return nums;
    }
};

