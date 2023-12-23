#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp(26, 0);
        for (char ch : s)
            mp[ch - 'a']++;
        for (char ch : t) {
            mp[ch - 'a']--;
            if (mp[ch - 'a'] < 0)
                return false;
        }
            
        for (int val : mp)
            if (val != 0)
                return false;
        return true;
    }
};
