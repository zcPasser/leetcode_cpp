#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricSize = prices.size();
        vector<vector<int>> dp(pricSize, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] -= prices[0];
        for (int i = 1; i < pricSize; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max( - prices[i], dp[i - 1][1]);
        }
        return max(dp[pricSize - 1][0], dp[pricSize - 1][1]);
    }
};

