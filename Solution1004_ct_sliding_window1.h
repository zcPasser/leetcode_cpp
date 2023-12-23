#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int numsSize = nums.size();
        int ans = 0;
        int left = 0, right = 0;
        int cntOne = 0;
        while (right < numsSize) {
            if (nums[right] == 1)
                cntOne++;
            right++;
            if (right - left > cntOne + k) {
                if (nums[left] == 1)
                    cntOne--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};

