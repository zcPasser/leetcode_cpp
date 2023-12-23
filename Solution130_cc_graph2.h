#pragma once
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                que.push({ i,0 });
            if (board[i][n - 1] == 'O')
                que.push({ i,n-1 });
        }
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O')
                que.push({ 0,j });
            if (board[m - 1][j] == 'O')
                que.push({ m-1,j });
        }
        while (!que.empty()) {
            pair<int, int> cur = que.front();
            board[cur.first][cur.second] = 'A';
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int nextx = cur.first + dir[i][0];
                int nexty = cur.second + dir[i][1];
                if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size())
                    continue;
                if (board[nextx][nexty] == 'O')
                    que.push({ nextx,nexty });
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};

