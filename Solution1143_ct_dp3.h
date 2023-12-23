#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1Size = text1.size(), t2Size = text2.size();
        if (t1Size * t2Size == 0)
            return 0;
        vector<vector<int>> LCS(t1Size + 1, vector<int>(t2Size + 1, 0));
        for (int i = 1; i <= t1Size; ++i)
        {
            for (int j = 1; j <= t2Size; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
            }
        }
        return LCS[t1Size][t2Size];
    }
};
