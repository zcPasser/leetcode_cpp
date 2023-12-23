#pragma once
#include<vector>
#include<string>
class Solution {
private:
    int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    std::vector<std::vector<bool>> used;
    int m, n;
    bool backtracking(std::vector<std::vector<char>>& board, int row, int col, int size,
        const std::string& word, int wordSize) {
        if (board[row][col] != word[size])
            return false;
        else if (size == wordSize - 1)
            return true;

        used[row][col] = true;
        int newRow = row, newCol = col;
        for (int i = 0; i < 4; ++i) {
            newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (0 <= newRow && newRow < m && 0 <= newCol && newCol < n) {
                if (!used[newRow][newCol]) {
                    if (backtracking(board, newRow, newCol, size + 1,
                        word, wordSize)) {
                        return true;
                    }
                }
            }
        }
        used[row][col] = false;
        return false;
    }
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        using namespace std;
        m = board.size(), n = board[0].size();
        int wordSize = word.size();
        used.resize(m, vector<bool>(n, false));
        bool ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtracking(board, i, j, 0, word, wordSize))
                    return true;
            }
        }
        return false;
    }
};

