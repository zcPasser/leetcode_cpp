#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // —°‘Ò≈≈–Ú
        int nsSize = nums.size();
        int idx = -1;
        for (int i = 0; i < nsSize - 1; i++) {
            idx = i;
            for (int j = i + 1; j < nsSize; j++) {
                if (nums[idx] > nums[j])
                    idx = j;
            }
            swap(nums[i], nums[idx]);
        }
        return nums;
    }
};
