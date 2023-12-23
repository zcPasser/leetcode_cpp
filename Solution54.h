#pragma once
#include<vector>
using namespace std;

class Solution54
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n, 0);
        int cnt = 0;
        int start_x = 0, start_y = 0;
        int min_ = min(m, n);
        int loop = min_ / 2;
        int mid = min_ / 2;
        int offset = 1;
        while (loop) {
            loop--;
            int i = start_x, j = start_y;
            while (j < (start_y + n - offset)) {
                ans[cnt++] = matrix[i][j++];
            }
            while (i < (start_x + m - offset)) {
                ans[cnt++] = matrix[i++][j];
            }
            while (j > start_y) {
                ans[cnt++] = matrix[i][j--];
            }
            while (i > start_x) {
                ans[cnt++] = matrix[i--][j];
            }
            start_x++, start_y++;
            offset += 2;
        }
        if (min_ % 2) {
            if (m > n) {
                for (int i = mid; i < mid + m - n + 1; i++) {
                    ans[cnt++] = matrix[i][mid];
                }
            }
            else {
                for (int j = mid; j < mid + n - m + 1; j++) {
                    ans[cnt++] = matrix[mid][j];
                }
            }
        }
        return ans;
    }
};

