#pragma once
#include<vector>
#include<string>
class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        using namespace std;
        int strsSize = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int zeroNums = 0, oneNums = 0;
        for (int i = 0; i < strsSize; ++i) {
            zeroNums = 0, oneNums = 0;
            for (const char& ch : strs[i]) {
                if (ch == '0')
                    ++zeroNums;
                else
                    ++oneNums;
            }
            for (int p = m; p >= zeroNums; --p) {
                for (int q = n; q >= oneNums; --q) {
                    dp[p][q] = max(dp[p][q], dp[p - zeroNums][q - oneNums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

