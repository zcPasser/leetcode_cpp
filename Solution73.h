#pragma once
#include<vector>
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        using namespace std;
        int row = matrix.size(), col = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for(int i=0;i<row;++i)
            if (!matrix[i][0]) {
                firstCol = true;
                break;
            }
        for (int i = 0; i < col; ++i)
            if (!matrix[0][i]) {
                firstRow = true;
                break;
            }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
        if (firstRow) {
            for (int i = 0; i < col; ++i)
                matrix[0][i] = 0;
        }
    }
};

