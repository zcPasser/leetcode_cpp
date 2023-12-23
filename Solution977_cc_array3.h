#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int nsSize = nums.size();
        int left = 0, right = nsSize - 1;
        vector<int> ans(nsSize, 0);
        int idx = nsSize - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                ans[idx--] = nums[right] * nums[right];
                right--;
            }
            else {
                ans[idx--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
