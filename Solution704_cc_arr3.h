#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nsSize = nums.size();
        int left = 0, right = nsSize - 1;
        int mid = 0;
        while (left <= right) {
            mid = ((right - left) >> 1) + left;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};
