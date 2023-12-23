#pragma once
#include <string>
using namespace std;
class Solution383
{
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (char ch : magazine) {
            cnt[ch - 'a']++;
        }
        for (char ch : ransomNote) {
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0)
                return false;
        }
        for (int val : cnt) {
            if (val < 0)
                return false;
        }
        return true;
    }
};

