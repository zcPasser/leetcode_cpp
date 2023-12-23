#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    int dir[4][2] = { {0,1}, {1,0}, {0,-1},{-1, 0} };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        
        int cnt = m * n;
        int x = 0, y = 0;
        vector<int> ans;
        int dirIdx = 0;
        while (cnt-- > 0)
        {
            //cnt--;
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -200;
            int nextx = x + dir[dirIdx][0], nexty = y + dir[dirIdx][1];
            if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || matrix[nextx][nexty] == -200)
                dirIdx = (dirIdx + 1) % 4;
            x += dir[dirIdx][0], y += dir[dirIdx][1];
        }
        return ans;
    }
};
