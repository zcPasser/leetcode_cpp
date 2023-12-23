#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        using namespace std;
        int numsSize = nums.size();
        if (numsSize < 2)
            return false;
        unordered_map<int, int> uomp;
        uomp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < numsSize; ++i) {
            remainder = (remainder + nums[i]) % k;
            if (uomp.count(remainder)) {
                if (i - uomp[remainder] >= 2)
                    return true;
            }
            else
                uomp[remainder] = i;
        }
        return false;
    }
};

