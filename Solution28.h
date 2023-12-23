#pragma once
#include <string>
using namespace std;
class Solution28
{
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        int lenNeedle = needle.size();
        if (lenNeedle == 0)
            return 0;
        int * next = new int[lenNeedle];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == lenNeedle)
                return i - lenNeedle + 1;
        }
        return -1;
    }
};

