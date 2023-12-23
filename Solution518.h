#pragma once
#include<vector>
class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        using namespace std;
        int coinsSize = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coinsSize; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

