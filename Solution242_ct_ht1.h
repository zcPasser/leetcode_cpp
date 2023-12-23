#pragma once
#include<string>
#include<unordered_map>
#include<vector>
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        using namespace std;
        int sSize = s.size(), tSize = t.size();
        if (sSize != tSize)
            return false;
        //unordered_map<char, int> mp;
        //for (const char& ch : s)
        //    ++mp[ch];
        //for (const char& ch : t) {
        //    if (mp[ch] == 0)
        //        return false;
        //    else
        //        --mp[ch];
        //}
        vector<int> mp(26, 0);
        for (const char& ch : s)
            ++mp[ch - 'a'];
        for (const char& ch : t) {
            if (mp[ch - 'a'] == 0)
                return false;
            else
                --mp[ch - 'a'];
        }
        return true;
    }
};

