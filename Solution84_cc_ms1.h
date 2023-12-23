#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        using namespace std;
        int heightsSize = heights.size();
        if (heightsSize == 0)
            return 0;
        stack<int> stk;
        stk.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0); 
        heightsSize = heights.size();
        int ans = 0;
        for (int i = 1; i < heightsSize; ++i) {
            while (heights[i] < heights[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                int w = i - stk.top() - 1;
                ans = max(ans, w * heights[mid]);
            }
            stk.push(i);
        }
        return ans;
    }
};

