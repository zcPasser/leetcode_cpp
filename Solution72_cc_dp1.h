#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        using namespace std;
        int word1Size = word1.size(), word2Size = word2.size();
        if (word1Size * word2Size == 0)
            return word1Size + word2Size;
        vector<vector<int>> dp(word1Size + 1, vector<int>(word2Size + 1));
        for (int i = 1; i <= word1Size; ++i)
            dp[i][0] = i;
        for (int i = 1; i <= word2Size; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= word1Size; ++i) {
            for (int j = 1; j <= word2Size; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        return dp[word1Size][word2Size];
    }
};

