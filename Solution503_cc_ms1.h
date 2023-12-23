#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        using namespace std;
        int numsSize = nums.size();
        vector<int> ans(numsSize, -1);
        stack<int> stk;
        for (int i = 0; i < numsSize; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for (int i = 0; i < numsSize; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                if (ans[stk.top()] == -1)
                    ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

