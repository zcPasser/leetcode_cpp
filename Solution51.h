#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<string> chessBoard;
    vector<vector<string>> ans;
    int n;
    bool isLegal(int r, int c) {
        //越界判定
        if (r < 0 || r >= n)
            return false;
        if (c < 0 || c >= n)
            return false;
        //棋盘攻击判定
        //同列
        for (int i = 0; i < r; i++) {
            if (chessBoard[i][c] == 'Q')
                return false;
        }
        //斜线
        //135度
        for (int i = r - 1, j = c + 1; i >=0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q')
                return false;
        }
        //45度
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtracking(int r) {
        if (r == n) {
            ans.push_back(chessBoard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isLegal(r, i)) {
                chessBoard[r][i] = 'Q';
                backtracking(r + 1);
                chessBoard[r][i] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        chessBoard.resize(n, string(n, '.'));
        ans.clear();
        backtracking(0);
        return ans;
    }
};
