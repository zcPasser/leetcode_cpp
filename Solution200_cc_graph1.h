#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> visited;
    int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
    void dfs(const vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                continue;
            if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                //visited[nextX][nextY] = true;
                dfs(grid, nextX, nextY);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        /// <summary>
        /// Á¬Í¨×ÓÍ¼
        /// </summary>
        /// <param name="grid"></param>
        /// <returns></returns>
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<int>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;                    
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

