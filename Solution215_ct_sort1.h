#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right)
            return nums[k];
        int partition = nums[left], i = left - 1, j = right + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)
            return quickSelect(nums, left, j, k);
        else
            return quickSelect(nums, j + 1, right, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nsSize = nums.size();
        return quickSelect(nums, 0, nsSize - 1, nsSize - k);
    }
};

