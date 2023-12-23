#pragma once
#include<vector>
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        using namespace std;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        int mid = 0;
        int row = 0, col = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            row = mid / n, col = mid % n;
            if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else if (matrix[row][col] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};

