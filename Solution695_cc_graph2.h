#pragma once
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<bool>> visited;
    int cnt = 0;
    void dfs(const vector<vector<int>>& grid, int x, int y) {
        visited[x][y] = true;
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                continue;
            if (grid[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                //visited[nextX][nextY] = true;
                //++cnt;
                dfs(grid, nextX, nextY);
            }
        }

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    cnt = 0;
                    dfs(grid, i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};

