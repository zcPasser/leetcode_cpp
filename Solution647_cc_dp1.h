#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int countSubstrings(std::string s) {
        using namespace std;
        int sSize = s.size();
        vector<vector<bool>> dp(sSize, vector<bool>(sSize, false));
        int ans = 0;
        for (int i = sSize - 1; i >= 0; --i) {
            for (int j = i; j < sSize; ++j) {
                if (s[i] == s[j]) {
                    if ((j - i) <= 1) {
                        ++ans;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) {
                        ++ans;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ans;
    }
};
