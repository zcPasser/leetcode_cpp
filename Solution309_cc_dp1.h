#pragma once
#include<vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        using namespace std;
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < pricesSize; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], max(dp[(i - 1) % 2][1] - prices[i], dp[(i - 1) % 2][3] - prices[i]));
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]);
            dp[i % 2][2] = dp[(i - 1) % 2][0] + prices[i];
            dp[i % 2][3] = dp[(i - 1) % 2][2];
        }
        return max(dp[(pricesSize - 1) % 2][1], max(dp[(pricesSize - 1) % 2][2], dp[(pricesSize - 1) % 2][3]));
    }
};

