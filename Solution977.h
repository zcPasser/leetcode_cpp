#pragma once
#include <stdio.h>
#include <vector>

using namespace std;
class Solution977
{
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len_nums = nums.size();
        int left = 0, right = len_nums - 1;
        vector<int> ans(len_nums);
        int i = right;
        while (left <= right) {
            int left_val = abs(nums[left]), right_val = abs(nums[right]);
            if (left_val < right_val) {
                ans[i] = right_val * right_val;
                right--;
            }
            else {
                ans[i] = left_val * left_val;
                left++;
            }
            i--;
        }
        return ans;
    }
};

