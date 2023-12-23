#pragma once
#include<vector>
#include<bitset>
class Solution {
private:
    std::vector<std::bitset<9>> rows;
    std::vector<std::bitset<9>> cols;
    std::vector<std::vector<std::bitset<9>>> cells;
    std::bitset<9> getPossibleStatus(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }
    std::vector<int> getNext(std::vector<std::vector<char>>& board) {
        std::vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.')
                    continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt)
                    continue;
                ret = { i,j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x / 3][y / 3][n] = (fillFlag) ? 1 : 0;
    }

    bool backtracking(std::vector<std::vector<char>>& board, int cnt) {
        if (cnt == 0)
            return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); ++n) {
            if (!bits.test(n))
                continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (backtracking(board, cnt - 1))
                return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }
public:

    void solveSudoku(std::vector < std::vector<char >> &board) {
        using namespace std;
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        backtracking(board, cnt);
    }
};
