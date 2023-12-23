#pragma once
#include <vector>
using namespace std;
class Solution59
{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int loop = n / 2;
        int i = 0, j = 0;
        int mid = n / 2;
        int cnt = 1;
        int offset = 1;
        int start_x = 0, start_y = 0;
        while (loop) {
            loop--;
            i = start_x, j = start_y;
            while (j < (n - offset)) {
                ans[i][j] = cnt++;
                j++;
            }
            while (i < (n - offset)) {
                ans[i][j] = cnt++;
                i++;
            }
            while (j > start_y) {
                ans[i][j] = cnt++;
                j--;
            }
            while (i > start_x) {
                ans[i][j] = cnt++;
                i--;
            }
            start_x++, start_y++;
            offset++;
        }
        if (n % 2) {
            ans[mid][mid] = cnt;
        }

        return ans;
    }
};

