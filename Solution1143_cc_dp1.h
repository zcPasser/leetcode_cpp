#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        using namespace std;
        int text1Size = text1.size(), text2Size = text2.size();
        vector<vector<int>> dp(text1Size, vector<int>(text2Size, 0));
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int i = 1; i < text1Size; ++i)
            dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
        for (int i = 1; i < text2Size; ++i)
            dp[0][i] = text1[0] == text2[i] ? 1 : dp[0][i - 1];

        for (int i = 1; i < text1Size; ++i) {
            for (int j = 1; j < text2Size; ++j) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[text1Size - 1][text2Size - 1];
    }
};

