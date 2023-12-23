#pragma once
#include<vector>
class Solution {
public:
    int integerBreak(int n) {
        using namespace std;
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j)
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
        return dp[n];
    }
};

