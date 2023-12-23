#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<char>> chessboard;
    int n;
    int ans;
    bool isLegal(int row, int col) {
        //检查同列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] != '.')
                return false;
        }
        //检查45度
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] != '.')
                return false;
        }
        //检查135度
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] != '.')
                return false;
        }
        return true;
    }
    void backtracking(int curLevel) {
        if (curLevel == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isLegal(curLevel, i)) {
                chessboard[curLevel][i] = 'Q';
                backtracking(curLevel + 1);
                chessboard[curLevel][i] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        this->ans = 0;
        this->n = n;
        chessboard.resize(n, vector<char>(n, '.'));
        backtracking(0);
        return this->ans;
    }
};

