#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int nsSize = nums.size();
        int left = 0, right = 0;
        int ans = INT32_MAX;
        int winSum = 0;
        while (right < nsSize) {
            winSum += nums[right];
            while (winSum >= target) {
                ans = min(ans, right - left + 1);
                winSum -= nums[left];
                left++;                
            }
            right++;

        }
        return ans == INT32_MAX ? 0 : ans;
    }
};
