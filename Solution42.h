#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int heightSize = height.size();
        if (heightSize < 3)
            return 0;
        vector<int> leftMax(heightSize, 0), rightMax(heightSize, 0);
        leftMax[0] = height[0], rightMax[heightSize - 1] = height[heightSize - 1];
        for (int i = 1; i < heightSize; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = heightSize - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < heightSize; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

