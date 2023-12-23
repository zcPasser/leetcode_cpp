#pragma once
#include<vector>
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        using namespace std;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < col; ++i)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};
