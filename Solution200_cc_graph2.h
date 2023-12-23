#pragma once
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> visited;
    int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
    void bfs(const vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            pair<int, int> cell = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int nextX = cell.first + dir[i][0];
                int nextY = cell.second + dir[i][1];
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                    continue;
                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                    visited[nextX][nextY] = true;
                    que.push({ nextX, nextY });
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<int>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
