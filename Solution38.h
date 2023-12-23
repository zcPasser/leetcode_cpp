#pragma once
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if (n < 2)
            return ans;
        for (int i = 2; i < n; i++) {
            string tmp = "";
            char preCh = ans[0];
            int cnt = 0;
            for (auto ch : ans) {
                if (ch == preCh) {
                    cnt++;
                }
                else {
                    tmp += to_string(cnt) + preCh;
                    cnt = 1;
                    preCh = ch;
                }
            }
            ans = tmp + to_string(cnt) + preCh;
        }
        return ans;
    }
};

