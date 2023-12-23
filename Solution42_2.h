#pragma once
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int heightSize = height.size();
        if (heightSize < 3)
            return 0;
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < heightSize; i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;
                int left = stk.top();
                ans += (i - left - 1) * (min(height[left], height[i]) - height[top]);
            }
            stk.push(i);
        }
        return ans;
    }
};

