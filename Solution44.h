#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= pSize; i++)
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        for (int i = 1; i <= sSize; i++) {
            for (int j = 1; j <= pSize; j++) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
        }
        return dp[sSize][pSize];
    }
};

