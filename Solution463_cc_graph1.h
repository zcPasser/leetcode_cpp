#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 1;
        if (grid[r][c] == 0)
            return 1;
        if (grid[r][c] != 1)
            return 0;
        grid[r][c] = 2;
        return dfs(grid, r - 1, c, m, n)
            + dfs(grid, r + 1, c, m, n)
            + dfs(grid, r, c - 1, m, n)
            + dfs(grid, r, c + 1, m, n);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    return dfs(grid, i, j, m, n);
            }
        }
        return 0;
    }
};

