#pragma once
#include<vector>
#include<stack>
class Solution {
private:
    int largestRectangleArea(std::vector<int>& heights) {
        using namespace std;
        int heightsSize = heights.size();
        vector<int> left(heightsSize, -1), right(heightsSize, heightsSize);
        stack<int> stk1, stk2;
        for (int i = 0; i < heightsSize; ++i) {
            while (!stk1.empty() && heights[stk1.top()] >= heights[i])
                stk1.pop();
            if (stk1.empty())
                left[i] = -1;
            else
                left[i] = stk1.top();
            stk1.push(i);
        }
        for (int i = heightsSize - 1; i >= 0; --i) {
            while (!stk2.empty() && heights[stk2.top()] >= heights[i])
                stk2.pop();
            if (stk2.empty())
                right[i] = heightsSize;
            else
                right[i] = stk2.top();
            stk2.push(i);
        }
        int ans = 0;
        for (int i = 0; i < heightsSize; ++i)
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        return ans;

    }
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        using namespace std;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};

