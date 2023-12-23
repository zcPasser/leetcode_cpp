#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        using namespace std;
        int temperSize = temperatures.size();
        vector<int> ans(temperSize);
        stack<int> stk;
        for (int i = 0; i < temperSize; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int preIdx = stk.top();
                ans[preIdx] = i - preIdx;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

