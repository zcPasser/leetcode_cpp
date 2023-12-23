#pragma once
#include<vector>
#include<limits>
class Solution {
public:
    int numSquares(int n) {
        using namespace std;
        if (n <= 3)
            return n;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 1;
        for (int i = 5; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};
