#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        for (char& ch : s)
            if (ch != '#')
                stk1.push(ch);
            else if (!stk1.empty())
                stk1.pop();
        for (char& ch : t)
            if (ch != '#')
                stk2.push(ch);
            else if (!stk2.empty())
                stk2.pop();
        while (!stk1.empty() && !stk2.empty()) {
            if (stk1.top() != stk2.top())
                return false;
            stk1.pop(), stk2.pop();
        }
        return stk1.empty() && stk2.empty();
    }
};