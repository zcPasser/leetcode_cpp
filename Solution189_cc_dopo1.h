#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    void reverse(vector<int>& nums, int begin, int end) {
        if (begin < end && end < nums.size()) {
            for (int i = begin, j = end; i < j; ++i, --j) {
                swap(nums[i], nums[j]);
            }
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        k %= numsSize;
        this->reverse(nums, 0, numsSize - 1);
        this->reverse(nums, 0, k - 1);
        this->reverse(nums, k, numsSize - 1);
    }
};
