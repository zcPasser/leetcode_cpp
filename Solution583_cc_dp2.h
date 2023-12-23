#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        using namespace std;
        int w1Size = word1.size(), w2Size = word2.size();
        vector<vector<int>> dp(w1Size + 1, vector<int>(w2Size + 1, 0));
        for (int i = 1; i <= w1Size; ++i) {
            for (int j = 1; j <= w2Size; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return w1Size + w2Size - dp[w1Size][w2Size] * 2;
    }
};


