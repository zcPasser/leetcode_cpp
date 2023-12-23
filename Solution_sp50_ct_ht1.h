#pragma once
#include<string>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        int hash[26] = { 0 };
        for (const char& ch : s)
            ++hash[ch - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (hash[s[i]-'a'] == 1)
                return s[i];
        return ' ';
    }
};

