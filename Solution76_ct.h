#pragma once
#include<string>
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        using namespace std;
        int need[128] = {0};
        int sSize = s.size(), tSize = t.size();
        if (sSize < tSize)
            return "";
        for (const char& ch : t)
            need[ch]++;
        int lhs = 0, rhs = 0, needCnt = tSize;
        int ans[2] = { -1, sSize };
        while (rhs < sSize) {
            if (need[s[rhs]] > 0)
                --needCnt;
            --need[s[rhs]];
            if (needCnt == 0) {
                while (lhs < rhs && need[s[lhs]] < 0) {
                    ++need[s[lhs]];
                    ++lhs;
                }
                if ((rhs - lhs) < (ans[1] - ans[0]))
                    ans[0] = lhs, ans[1] = rhs;
            }
            ++rhs;
        }
        if (ans[0] == -1)
            return "";
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};

