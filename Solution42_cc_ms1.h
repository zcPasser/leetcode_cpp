#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    int trap(std::vector<int>& height) {
        using namespace std;
        int heightSize = height.size();
        if (heightSize < 3)
            return 0;
        stack<int> stk;
        //stk.push(0);
        int ans = 0;
        for (int i = 0; i < heightSize; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int h = min(height[stk.top()], height[i]) - height[mid];
                    int w = i - stk.top() - 1;
                    ans += h * w;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};

