#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        int ans = 1;
        int lastOrder = 0;
        int curOrder = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curOrder = nums[i + 1] - nums[i];
            if ((lastOrder <= 0 && curOrder > 0) || (lastOrder >= 0 && curOrder < 0)) {
                ans++;
                lastOrder = curOrder;
            }
        }
        return ans;
    }
};

