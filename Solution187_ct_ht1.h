#pragma once
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sSize = s.size();
        if (sSize < 10)
            return {};
        //unordered_set<char> uose = { 'A','C','G','T' };
        unordered_map<string, int> uomp;
        vector<string>ans;

        uomp[s.substr(0, 10)]++;

        for (int i = 0; i + 10 <= sSize; ++i) {
           uomp[s.substr(i, 10)]++;
        }
        for (const auto& it : uomp) {
            if (it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};

