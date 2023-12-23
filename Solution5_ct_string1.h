#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        vector<vector<bool>> dp(sSize, vector<bool>(sSize, false));
        int maxSize = 0;
        int begin = 0;
        for (int i = sSize-1; i >=0; --i) {
            for (int j = i; j < sSize; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxSize) {
                    maxSize = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxSize);
    }
};

