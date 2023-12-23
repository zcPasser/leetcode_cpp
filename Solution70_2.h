#pragma once
#include<vector>
class Solution {
public:
    int climbStairs(int n) {
        using namespace std;
        if (n < 3)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= 2; ++i) {
                if (j - i >= 0)
                    dp[j] += dp[j - i];
            }
        }
        return dp[n];
    }
};

