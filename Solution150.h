#pragma once
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                if (s == "+")
                    stk.push(op1 + op2);
                if (s == "-")
                    stk.push(op2 - op1);
                if (s == "*")
                    stk.push(op1 * op2);
                if (s == "/")
                    stk.push(op2 / op1);
            }
            else
                stk.push(stoi(s));
        }
        int ans = stk.top();
        stk.pop();
        return ans;
    }
};

