#pragma once
#include<vector>
class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        using namespace std;
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        vector<int> dp(2 * k + 1, 0);
        int dpSize = dp.size();
        for (int i = 1; i < dpSize; i += 2) {
            dp[i] -= prices[0];
        }
        for (int i = 1; i < pricesSize; ++i) {   
            for (int j = 1; j < dpSize; j+=2) {
                dp[j] = max(dp[j], dp[j - 1] - prices[i]);
            }
            for (int j = 2; j < dpSize; j += 2)
                dp[j] = max(dp[j], dp[j - 1] + prices[i]);
        }
        return dp[dpSize - 1];
    }
};

