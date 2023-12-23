#pragma once
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int sSize = s.size();
        if (sSize < 2 || numRows == 1)
            return s;
        string ans = "";
        int cnt = 2;
        int idx = 0;
        while (idx < sSize) {
            ans += s[idx];
            idx = cnt * (numRows - 1);
            cnt += 2;
        }
        for (int i = 1; i < numRows - 1 && i < sSize; i++) {
            ans += s[i];
            cnt = 2;
            idx = cnt * (numRows - 1) - i;
            while (idx < sSize) {
                ans += s[idx];
                idx = cnt * (numRows - 1) + i;
                if (idx < sSize)
                    ans += s[idx];
                else
                    break;
                cnt += 2;
                idx = cnt * (numRows - 1) - i;
            }
        }
        cnt = 3;
        idx = numRows - 1;
        while (idx < sSize) {
            ans += s[idx];
            idx = cnt * (numRows - 1);
            cnt += 2;
        }
        return ans;
    }
};

