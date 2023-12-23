#pragma once
#include<vector>
#include<string>
#include<unordered_set>
class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        using namespace std;
        int wordDictSize = wordDict.size(), sSize = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(sSize + 1, false);
        dp[0] = true;
        for (int j = 1; j <= sSize; ++j) {
            for (int i = 0; i < j; ++i) {
                string word = s.substr(i, j - i);
                if (set.find(word) != set.end() && dp[i])
                    dp[j] = true;
            }
        }
        return dp[sSize];
    }
};

