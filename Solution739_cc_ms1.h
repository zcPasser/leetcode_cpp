#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        using namespace std;
        int temperSize = temperatures.size();
        vector<int> ans(temperSize, 0);
        stack<int> stk;
        for (int i = 0; i < temperSize; ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
