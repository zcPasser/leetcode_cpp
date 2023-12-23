#pragma once
#include<vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        int slow = 2, fast = 2;
        while (fast < numsSize) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
