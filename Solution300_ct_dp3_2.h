#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize < 2)
            return nsSize;
        vector<int> dpTail;
        dpTail.push_back(nums[0]);
        int end = 0;
        int left = 0, right = 0, mid = 0;
        for (int i = 1; i < nsSize; ++i) {
            if (dpTail[end] < nums[i]) {
                dpTail.push_back(nums[i]);
                ++end;
            }
            else {
                left = 0, right = end;
                while (left < right) {
                    mid = (right - left) / 2 + left;
                    if (dpTail[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid;
                }
                dpTail[left] = nums[i];
            }
            
        }
        return end + 1;
    }
};
