#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();

        int cnt = m * n;
        int startx = 0, starty = 0;
        int dy = n - 1, dx = m - 1;
        vector<int> ans(cnt, 0);
        int i = 0;
        while (i < cnt)
        {
            int x = startx, y = starty;
            while (y < starty + dy)
            {
                ans[i++]=matrix[x][y];
                y++;
            }
            if (i == cnt)
                break;
            while (x < startx + dx)
            {
                ans[i++] = matrix[x][y];
                x++;
            }
            if (i == cnt)
                break;
            while (y > starty)
            {
                ans[i++] = matrix[x][y];
                y--;
            }
            if (i == cnt)
                break;
            while (x > startx)
            {
                ans[i++] = matrix[x][y];
                x--;
            }
            startx++, starty++;
            dx--, dy--;
        }
        return ans;
    }
};
