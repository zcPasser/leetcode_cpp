#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        using namespace std;
        int sSize = s.size();
        if (sSize < 2)
            return sSize;
        vector<vector<int>> dp(sSize, vector<int>(sSize));
        for (int i = 0; i < sSize; ++i)
            dp[i][i] = 1;
        for (int i = sSize - 1; i >= 0; --i) {
            for (int j = i + 1; j < sSize; ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][sSize - 1];
    }
};

