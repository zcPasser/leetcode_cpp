#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    void backtracking(vector<string>& ans, int n, string& path, int leftCnt, int rightCnt)
    {
        if (n == leftCnt && n == rightCnt)
        {
            ans.push_back(path);
            return;
        }
        if (leftCnt > rightCnt)
        {
            path.push_back(')');
            backtracking(ans, n, path, leftCnt, rightCnt + 1);
            path.pop_back();
        }
        if (leftCnt < n)
        {
            path.push_back('(');
            backtracking(ans, n, path, leftCnt + 1, rightCnt);
            path.pop_back();
        }

        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return { "()" };
        vector<string> ans;
        string path = "";
        backtracking(ans, n, path, 0, 0);
        return ans;
    }
};

