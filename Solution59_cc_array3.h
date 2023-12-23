#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int startx = 0, starty = 0;
        int round = n / 2;
        int mid = n / 2;
        int offset = 1;
        int val = 1;
        for (int i = 0; i < round; ++i) {
            x = startx, y = starty;
            while (y < n - offset) {
                ans[x][y] = val++;
                y++;
            }
            while (x < n - offset) {
                ans[x][y] = val++;
                x++;
            }
            while (y > starty) {
                ans[x][y] = val++;
                y--;
            }
            while (x > startx) {
                ans[x][y] = val++;
                x--;
            }
            startx++, starty++;
            offset++;
        }
        if (n % 2)
            ans[mid][mid] = val;
        return ans;
    }
};

