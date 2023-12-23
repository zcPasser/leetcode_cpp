#pragma once
#include <string>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Size = word1.size(), w2Size = word2.size();
        if (w1Size * w2Size == 0)
            return w1Size + w2Size;
        vector<vector<int>> dp(w1Size + 1, vector<int>(w2Size + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i < w2Size + 1; i++)
            dp[0][i] = i;
        for (int i = 1; i < w1Size + 1; i++)
            dp[i][0] = i;
        for(int i=1;i<w1Size+1;i++)
            for (int j = 1; j < w2Size+1; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        return dp[w1Size][w2Size];
    }
};

