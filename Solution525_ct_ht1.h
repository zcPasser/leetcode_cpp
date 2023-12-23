#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return 0;
        int preSum = 0;
        unordered_map<int, int> uomp;
        uomp[0] = -1;
        int ans = 0;
        for (int i = 0; i < numsSize; ++i) {
            int num = nums[i];
            if (num == 1)
                ++preSum;
            else
                --preSum;
            if (uomp.count(preSum)) {
                ans = max(ans, i - uomp[preSum]);
            }
            else
                uomp[preSum] = i;
        }
        return ans;
    }
};
