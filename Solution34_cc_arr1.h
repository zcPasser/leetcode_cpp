#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1, ans = nums.size();
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if(leftIdx<=rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
            return { leftIdx, rightIdx };
        return { -1,-1 };
    }
};

