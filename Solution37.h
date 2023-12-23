#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    bool isLegal(const vector<vector<char>>& board, int row, int col, char val) {
        //ͬ��ͬ��
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val || board[i][col] == val)
                return false;
        }
        //ͬ3*3
        int beginRow = row / 3 * 3, beginCol = col / 3 * 3;
        for(int i=beginRow;i<beginRow+3;i++)
            for (int j = beginCol; j < beginCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isLegal(board, row, col, val)) {
                            board[row][col] = val;
                            if(backtracking(board)) return true;
                            board[row][col] = '.';
                        }
                            
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

