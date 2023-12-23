#pragma once
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int sSize = s.size();
        if (sSize < 2)
            return 0;
        stack<int> stk;
        stk.push(-1);
        int ans = 0, cnt = 0;
        for (int i = 0; i < sSize; i++) {
            if (s[i] == ')') {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    ans = max(ans, i - stk.top());
                }
            }
            else {
                stk.push(i);
            }
        }
        return ans;
    }
};

