#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize < 2)
            return numsSize;
        vector<int> dp(numsSize, 1);
        vector<int> cnt(numsSize, 1);
        //int cnt[] = { 1,numsSize };
        int maxCnt = 1;
        for (int i = 1; i < numsSize; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        cnt[i] = cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if (dp[i] == dp[j] + 1)
                        cnt[i] += cnt[j];
                }
                if (dp[i] > maxCnt)
                    maxCnt = dp[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < numsSize; ++i)
            if (maxCnt == dp[i])
                ans += cnt[i];
        return ans;
    }
};
