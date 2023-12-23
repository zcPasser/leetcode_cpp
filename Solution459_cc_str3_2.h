#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sSize = s.size();
        vector<int> next(sSize, 0);
        //getNext(s, next);
        if (next[sSize - 1] != -1 && sSize % (sSize - (next[sSize - 1] + 1)) == 0)
            return true;
        return false;
    }
};

