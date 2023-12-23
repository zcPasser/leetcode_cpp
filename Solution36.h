#pragma once
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCnt[9][9];
        int colCnt[9][9];
        int squareCnt[3][3][9];
        memset(rowCnt, 0, sizeof(rowCnt));
        memset(colCnt, 0, sizeof(rowCnt));
        memset(squareCnt, 0, sizeof(rowCnt));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0' - 1;
                    if (rowCnt[i][idx] > 0)
                        return false;
                    if (colCnt[j][idx] > 0)
                        return false;
                    if (squareCnt[i / 3][j / 3][idx] > 0)
                        return false;
                    rowCnt[i][idx]++, colCnt[j][idx]++, squareCnt[i / 3][j / 3][idx]++;
                }
            }
        }
        return true;
    }
};

