#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)
            return;
        vector<int> arr(n, 0);
        int size = 0;
        int r = 0, c = n - 1;
        int tmp = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < c - r; j++) {
                tmp = matrix[r][r + j];
                matrix[r][r + j] = matrix[c - j][r];
                matrix[c - j][r] = matrix[c][c - j];
                matrix[c][c - j] = matrix[r + j][c];
                matrix[r + j][c] = tmp;
            }
            r++, c--;
            //size = n - 1 - 2 * i;
            //int idx = 0;
            //for (int j = i; j < i + size; j++)
                //arr[idx++] = matrix[i][j];
            //for (int d = 0; d < size; d++) {
                //matrix[i][i + d] = matrix[i + size - d][i];
                //matrix[i + size - d][i] = matrix[i + size][i + size - d];
                //matrix[i + size][i + size - d] = matrix[i + d][i + size];
                //matrix[i + d][i + size] = arr[d];
            //}
               
        }
    }
};

