#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return { "()" };
        vector<vector<string>> ans(n + 1);
        ans[0] = { "" };
        ans[1] = { "()" };
        string path = "";
        for (int i = 2; i <= n; i++)
        {
            for (int p = 0; p < i; p++)
            {
                int q = i - p - 1;
                if (q < 0)
                    break;
                for (auto first : ans[p])
                {
                    for (auto second : ans[q])
                    {
                        string s = "(" + first + ")" + second;
                        ans[i].push_back(s);
                    }
                }
            }
        }
        return ans[n];
    }
};

