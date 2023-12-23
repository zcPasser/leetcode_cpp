#pragma once
#include <string>
using namespace std;
class Solution459
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
    bool repeatedSubstringPattern(string s) {
        int lenS = s.size();
        if (lenS == 0)
            return false;
        int* next = new int[lenS];
        getNext(next, s);
        if (next[lenS - 1] != 0 && lenS % (lenS - next[lenS - 1]) == 0)
            return true;
        return false;
    }
};

