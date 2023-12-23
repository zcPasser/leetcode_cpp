#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int ans = 0;
    bool check(const vector<vector<char>>& chessboard, int row, int col,int n) {
        if (0 <= row && row < n && 0 <= col && col < n) {
            for (int i = 0; i < row; ++i)
                if (chessboard[i][col] == 'Q')
                    return false;
            for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
                if (chessboard[i][j] == 'Q')
                    return false;
            }
            for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
                if (chessboard[i][j] == 'Q')
                    return false;
            }
            return true;
        }
        return false;
    }
    void backtracking(vector<vector<char>>& chessboard, int row, int n) {
        if (row == n) {
            ++ans;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(chessboard, row, i, n)) {
                chessboard[row][i] = 'Q';
                backtracking(chessboard, row + 1, n);
                chessboard[row][i] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<char>> chessboard(n, vector<char>(n, '.'));
        backtracking(chessboard, 0, n);
        return ans;
    }
};

