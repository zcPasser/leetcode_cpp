#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        using namespace std;
        int heightsSize = heights.size();
        stack<int> stk1, stk2;
        vector<int> left(heightsSize, -1), right(heightsSize, heightsSize);
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
};

