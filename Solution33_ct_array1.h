#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nsSize = nums.size();
        if (nsSize == 0)
            return -1;
        if (nsSize == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = nsSize - 1;
        while (left <= right) {
            int mid = (right - left) >> 1 + left;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

