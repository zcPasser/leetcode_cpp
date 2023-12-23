#pragma once
#include<string>
#include<vector>
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        using namespace std;
        int sSize = s.size(), tSize = t.size();
        if (sSize < tSize)
            return 0;
        vector<unsigned long long> dp(tSize, 0);
        dp[0] = s[0] == t[0] ? 1 : 0;
        for (int i = 1; i < tSize; ++i)
            dp[i] = 0;
        for (int i = 1; i < sSize; ++i) {
            for (int j = tSize - 1; j >= 1; --j) {
                if (s[i] == t[j])
                    dp[j] += dp[j - 1];
            }
            dp[0] = s[i] == t[0] ? dp[0] + 1 : dp[0];
        }
        return dp[tSize - 1];
    }
};