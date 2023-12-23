#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    // dp
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;

        int maxSide = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                maxSide = 1;
            }
                
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                maxSide = 1;
            }
                


        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // 遇到 潜在正方形的左上角顶点
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    if (dp[i][j] > maxSide)
                        maxSide = dp[i][j];
                }
            }
        }
        return maxSide * maxSide;
    }
};

