#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int mod = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        vector<vector<int>> apples(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int hasApple = pizza[i][j] == 'A';
                if (i == m - 1 && j == n - 1)
                    apples[i][j] = hasApple;
                else if (i == m - 1)
                    apples[i][j] = hasApple + apples[i][j + 1];
                else if (j == n - 1)
                    apples[i][j] = hasApple + apples[i + 1][j];
                else
                    apples[i][j] = hasApple + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (apples[i][j])
                    dp[i][j][0] = 1;
                for (int p = 1; p < k; ++p) {
                    for (int x = i + 1; x < m; ++x)
                        if ((apples[i][j] - apples[x][j]) > 0)
                            dp[i][j][p] = (dp[i][j][p] + dp[x][j][p - 1]) % mod;
                    for (int y = j + 1; y < n; ++y)
                        if ((apples[i][j] - apples[i][y]) > 0)
                            dp[i][j][p] = (dp[i][j][p] + dp[i][y][p - 1]) % mod;
                }
            }
        }
        return dp[0][0][k - 1] % mod;
    }
};
