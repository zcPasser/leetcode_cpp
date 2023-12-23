#pragma once
#include<string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = { 0 };
        for (char ch : magazine)
            cnt[ch - 'a']++;
        for (char ch : ransomNote)
        {
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};
