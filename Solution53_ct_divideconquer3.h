#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int subQuestion(vector<int>& nums, int left, int right, int size) {
        if (left == right)
            return nums[left];

        int mid = (right - left) / 2 + left;
        int maxLeft = subQuestion(nums, left, mid, size);
        int maxRight = subQuestion(nums, mid + 1, right, size);
        
        //计算包含中间元素的最大子数组和
        int curSum = 0, maxL = nums[mid], maxR = nums[mid + 1];
        for (int i = mid; i >= 0; --i) {
            curSum += nums[i];
            maxL = max(curSum, maxL);
        }
        curSum = 0;
        for (int i = mid + 1; i < size; ++i) {
            curSum += nums[i];
            maxR = max(curSum, maxR);
        }

        return max(max(maxLeft, maxRight), maxL + maxR);
    }
public:
    int maxSubArray(vector<int>& nums) {
        int nsSize = nums.size();
        if (nsSize == 1)
            return nums[0];
        int ans = subQuestion(nums, 0, nsSize - 1, nsSize);
        return ans;
    }
};

