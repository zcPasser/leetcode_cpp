#pragma once
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char, char> uomp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
public:
    bool isValid(string s) {
        int sSize = s.size();
        if (sSize == 1)
            return false;
        stack<char> stk;
        for (char ch : s)
        {
            if (uomp.find(ch) == uomp.end())
                stk.push(ch);
            else
            {
                if (stk.empty())
                    return false;
                if (stk.top() != uomp[ch])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

