#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    // 暴力
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;

        int maxSide = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 遇到 潜在正方形的左上角顶点
                if (matrix[i][j] == '1')
                {
                    if (maxSide < 1)
                        maxSide = 1;
                    // 计算 当前潜在正方形 可能的最大边长
                    int currMaxSide = min(m - i, n - j);
                    for (int d = 1; d < currMaxSide; d++)
                    {
                        
                        bool flag = true;
                        if (matrix[i + d][j + d] == '0')
                            break;
                        // 判断 当前新增行 和 列是否均为 1
                        for (int k = 0; k < d; k++)
                        {
                            // 以 matrix[i+d][j+d]为参照物
                            if (matrix[i + d][j + k] == '0' || matrix[i + k][j + d] == '0')
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag & maxSide <= d)
                            maxSide = d + 1;
                        else if (!flag)
                            break;
                    }
                }
            }
        }
        return maxSide * maxSide;
    }
};

