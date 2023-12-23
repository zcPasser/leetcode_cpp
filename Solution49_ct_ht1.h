#pragma once
#include<vector>
#include<string>
#include<unordered_map>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        using namespace std;
        int strsSize = strs.size();
        if (strsSize < 2)
            return { strs };
        unordered_map<string, vector<string>> mp;
        //const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    //73, 79, 83, 89, 97, 101 };
        for (const string&s:strs) {
            string hashCode(26, '0');
            for (const char& ch : s)
                ++hashCode[ch - 'a'];
                //hashCode *= primes[ch - 'a'];
            mp[hashCode].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto it: mp)
            ans.emplace_back(it.second);
        return ans;
    }
};

