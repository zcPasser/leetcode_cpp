#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
    void getNext(const string& s, vector<int>& next)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j > -1 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                ++j;
            next[i] = j;
        }
        return;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int sSize = s.size();
        vector<int> next(sSize, 0);
        getNext(s, next);
        if(next[sSize - 1] != -1&& sSize % (sSize - (next[sSize - 1] + 1)) == 0)
            return true;
        return false;
    }
};

