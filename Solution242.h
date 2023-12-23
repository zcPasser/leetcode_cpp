#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution242
{
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(0, 26);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (char ch : t) {
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0) {
                return false;
            }
        }
        for (int val : cnt) {
            if (val != 0)
                return false;
        }
        return true;
    }
};

