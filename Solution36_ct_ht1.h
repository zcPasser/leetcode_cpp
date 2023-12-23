#pragma once
#include<vector>
#include<bitset>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> rows(9, bitset<9>(0)), cols(9, bitset<9>(0)), areas(9, bitset<9>(0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    int idx = i / 3 * 3 + j / 3;
                    if (rows[i][val - 1] == 1 || cols[j][val - 1] == 1 || areas[idx][val - 1] == 1)
                        return false;
                    rows[i][val - 1] = 1, cols[j][val - 1] = 1, areas[idx][val - 1] = 1;
                }
            }
        }
        return true;
    }
};

