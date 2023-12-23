#pragma once
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<bool>> visited;
    int bfs(const vector<vector<int>>& grid, int x, int y) {
        visited[x][y] = true;
        queue<pair<int, int>> que;
        que.push({ x,y });
        int cnt = 1;
        while (!que.empty()) {
            pair<int,int> cell = que.front();
            que.pop();
            int x = cell.first, y = cell.second;
            for (int i = 0; i < 4; ++i) {
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                    continue;
                if (grid[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    ++cnt;
                    que.push({ nextX,nextY });
                }
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};

