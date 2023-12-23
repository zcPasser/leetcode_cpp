#pragma once
#include<vector>
class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        using namespace std;
        int sum = 0;
        int stonesSize = stones.size();
        for (int i = 0; i < stonesSize; ++i) {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stonesSize; ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

