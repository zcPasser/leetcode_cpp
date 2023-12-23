#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    //vector<vector<bool>> visited;
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int cnt = 0;
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                continue;
            if (grid[nextx][nexty] != 0)
                dfs(grid, nextx, nexty);
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);
            if (grid[i][n - 1] == 1)
                dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);
            if (grid[m - 1][j] == 1)
                dfs(grid, m - 1, j);
        }
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    dfs(grid, i, j);
            }
        }
        return cnt;
    }
};

