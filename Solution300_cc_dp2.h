#pragma once
#include<vector>
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        vector<int> tail;
        tail.push_back(nums[0]);
        int end = 0;
        int left = 0, right = 0, mid = 0;
        for (int i = 1; i < numsSize; ++i) {
            if (nums[i] > tail[end]) {
                tail.push_back(nums[i]);
                ++end;
            }
            else {
                left = 0, right = end;
                while (left < right) {
                    mid = (right - left) / 2 + left;
                    if (tail[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid;
                }
                tail[left] = nums[i];
            }
        }
        
        return end + 1;
    }
};

