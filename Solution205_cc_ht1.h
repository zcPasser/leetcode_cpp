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
        unordered_map<char, int> s2T, t2S;
        for (int i = 0; i < sSize; ++i) {
            if ((s2T.count(s[i]) && s2T[s[i]]!=t[i]) || (t2S.count(t[i]) && t2S[t[i]] != s[i])) {
                    return false;
            }
            else {
                s2T[s[i]] = t[i];
                t2S[t[i]] = s[i];
            }
        }
        return true;
    }
};


