#pragma once
#include<string>
#include<vector>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        using namespace std;
        int sSize = s.size(), tSize = t.size();
        if (sSize > tSize)
            return false;
        if (sSize == 0)
            return true;
        vector<vector<int>> dp(sSize, vector<int>(tSize, 0));
        dp[0][0] = s[0] == t[0] ? 1 : 0;
        for (int i = 1; i < sSize; ++i)
            dp[i][0] = s[i] == t[0] ? 1 : dp[i - 1][0];
        for (int i = 1; i < tSize; ++i)
            dp[0][i] = s[0] == t[i] ? 1 : dp[0][i - 1];
        for (int i = 1; i < sSize; ++i) {
            for (int j = 1; j < tSize; ++j) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[sSize - 1][tSize - 1] == sSize;
    }
};

