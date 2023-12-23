#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize < 2)
            return;
        for (int i = nsSize - 1; i >= 0; --i) {
            for (int j = nsSize - 1; j > i; --j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};
