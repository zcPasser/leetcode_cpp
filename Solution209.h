#pragma once
#include <stdio.h>
#include <vector>
using namespace std;
class Solution209
{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len_nums = nums.size();
        int ans = INT32_MAX;
        int sum = 0;
        int start = 0, end = 0;
        int sub_len = 0;
        while (end < len_nums) {
            sum += nums[end];
            while (sum >= target) {
                sub_len = end - start + 1;
                ans = min(ans, sub_len);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

