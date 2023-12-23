#pragma once
#include<vector>
#include<limits>
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        using namespace std;
        int coinsSize = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coinsSize; ++i) {
            for (int j = coins[i]; j <= amount; ++j)
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
