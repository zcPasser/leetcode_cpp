#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {0,1},{0,-1}, {1,0},{-1,0} };
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '2' || grid[x][y] == '0')
            return;
        grid[x][y] = '2';
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx >= 0 && nextx < grid.size() && nexty >= 0 && nexty < grid[0].size())
                dfs(grid, nextx, nexty);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

