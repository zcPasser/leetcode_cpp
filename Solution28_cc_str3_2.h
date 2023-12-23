#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
    void getNext(const string& s, vector<int>& next)
    {
        int j = -1;
        int sSize = s.size();
        for (int i = 1; i < sSize; i++)
        {
            while (j > -1 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                ++j;
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        int hsSize = haystack.size(), nlSize = needle.size();
        if (hsSize * nlSize == 0)
            return -1;
        vector<int> next(nlSize, -1);
        getNext(needle, next);
        for (int i = 0, j = -1; i < hsSize; ++i)
        {
            while (j > -1 && haystack[i] != needle[j + 1])
                j = next[j];
            if (haystack[i] == needle[j + 1])
                ++j;
            if (j == nlSize - 1)
                return i - nlSize + 1;
        }
        return -1;
    }
};

