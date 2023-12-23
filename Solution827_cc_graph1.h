#pragma once
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
private:
    int cnt = 0;
    int m = 0, n = 0;
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark) {
        //if (visited[x][y] || grid[x][y] == 0)
        //    return;
        visited[x][y] = true;
        grid[x][y] = mark;
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n)
                continue;
            if (visited[nextx][nexty] || grid[nextx][nexty] == 0)
                continue;
            dfs(grid, visited, nextx, nexty, mark);
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, int> grid2Area;
        int mark = 2;
        bool isAllGrid = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    isAllGrid = false;
                if (!visited[i][j] && grid[i][j] == 1) {
                    cnt = 0;
                    dfs(grid, visited, i, j, mark);
                    grid2Area[mark] = cnt;
                    ++mark;
                }
            }
        }
        if (isAllGrid)
            return m * n;
        int ans = 0;
        unordered_set<int> visitedGrid;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmpCnt = 1;
                visitedGrid.clear();
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; ++k) {
                        int neari = i + dir[k][0];
                        int nearj = j + dir[k][1];
                        if (neari < 0 || neari >= m || nearj < 0 || nearj >= n)
                            continue;
                        if (visitedGrid.find(grid[neari][nearj]) != visitedGrid.end())
                            continue;
                        tmpCnt += grid2Area[grid[neari][nearj]];
                        visitedGrid.insert(grid[neari][nearj]);
                    }
                }
                ans = max(ans, tmpCnt);
            }
        }
        return ans;
    }
};

