#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution49
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string& s : strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            mp[s].emplace_back(tmp);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;

    }
};

