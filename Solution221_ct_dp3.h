#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    // ����
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
                // ���� Ǳ�������ε����ϽǶ���
                if (matrix[i][j] == '1')
                {
                    if (maxSide < 1)
                        maxSide = 1;
                    // ���� ��ǰǱ�������� ���ܵ����߳�
                    int currMaxSide = min(m - i, n - j);
                    for (int d = 1; d < currMaxSide; d++)
                    {
                        
                        bool flag = true;
                        if (matrix[i + d][j + d] == '0')
                            break;
                        // �ж� ��ǰ������ �� ���Ƿ��Ϊ 1
                        for (int k = 0; k < d; k++)
                        {
                            // �� matrix[i+d][j+d]Ϊ������
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

