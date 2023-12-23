#pragma once
#include <string>
#include <stack>
#include <map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        //"()[]{}"
        map<char, char> chToCh = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> stk;
        for (char ch : s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (stk.empty() || stk.top() != chToCh[ch])
                    return false;
                else {
                    stk.pop();
                }
            }
            else {
                stk.push(ch);
            }
                
        }
        return stk.empty();
    }
};

