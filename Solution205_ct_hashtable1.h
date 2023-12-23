#pragma once
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if (sSize != tSize)
            return false;
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < sSize; ++i) {
            if ((s2t.count(s[i]) && s2t[s[i]] != t[i]) || (t2s.count(t[i]) && t2s[t[i]] != s[i]))
                return false;
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        
        return true;
    }
};