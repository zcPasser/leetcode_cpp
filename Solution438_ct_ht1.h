#pragma once
#include<vector>
#include<string>
#include<unordered_map>
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        using namespace std;
        int sSize = s.size(), pSize = p.size();
        if (sSize < pSize)
            return {};
       int need[26]={0}, window[26]={};
        vector<int> ans;
        for (const char& ch : p)
            ++need[ch - 'a'];
        int validSum = 0;
        for (int i = 0; i < 26; ++i)
            if (need[i] > 0)
                ++validSum;
        int left = 0, right = 0;
        int valid = 0;
        int idx=0;
        while (right < sSize) {
            idx = s[right] - 'a';
            ++right;
            if (need[idx] > 0) {
                ++window[idx];
                if (window[idx] == need[idx])
                    ++valid;
            }
            while ((right - left) >= pSize) {
                if (valid == validSum)
                    ans.push_back(left);
                idx = s[left] - 'a';
                
                if (need[idx] > 0) {
                    if (need[idx] == window[idx])
                        --valid;
                    --window[idx];
                }
                ++left;
            }            
        }
        return ans;
    }
};

