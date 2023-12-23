#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        vector<vector<int>> dp(pricesSize, vector<int>(2, 0));
        dp[0][0] -= prices[0];

        for (int i = 1; i < pricesSize; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[pricesSize - 1][0], dp[pricesSize - 1][1]);
    }
};

