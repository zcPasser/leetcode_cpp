#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = strs.size();
        if (strsSize == 0)
            return "";
        else if (strsSize == 1)
            return strs[0];
        string ans = strs[0];
        int ansSize = strs[0].size();
        for (int i = 1; i < strsSize; i++)
            if (ansSize < strs[i].size()) {
                ansSize = strs[i].size();
                ans = strs[i];
            }
        int ansEnd = ansSize;
        for (const string& s : strs) {
            for (int i = 0; i < ansEnd; i++) {
                if (ans[i] != s[i]) {
                    ansEnd = i;
                    break;
                }
            }
            if (ansEnd == 0)
                break;
        }
        return ans.substr(0, ansEnd);
    }
};

