#pragma once
#include<vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        using namespace std;
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        int dp0 = -prices[0], dp1 = 0;
        for (int i = 1; i < pricesSize; ++i) {
            dp0 = max(dp0, dp1 - prices[i]);
            dp1 = max(dp1, dp0 + prices[i] - fee);
        }
        return dp1;
    }
};

