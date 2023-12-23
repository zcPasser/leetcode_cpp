#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int m = 0, n = 0;
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n)
                continue;
            if (heights[x][y] > heights[nextx][nexty] || visited[nextx][nexty])
                continue;
            dfs(heights, visited, nextx, nexty);
        }
        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({ i,j });
            }
        }
        return ans;
    }
};

