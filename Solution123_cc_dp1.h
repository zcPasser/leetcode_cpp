#pragma once
#include<vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        using namespace std;
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        vector<int> dp(4, 0);
        dp[0] -= prices[0];
        dp[2] = dp[0];
        for (int i = 1; i < pricesSize; ++i) {
            dp[0] = max(dp[0], 0 - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        return dp[3];
    }
};
