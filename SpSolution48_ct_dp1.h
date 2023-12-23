#pragma once
#include<string>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        using namespace std;
        int sSize = s.size();
        if (sSize < 2)
            return sSize;
        int left = 0, right = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (right < sSize) {
            ++mp[s[right]];
            while ((right - left + 1) > mp.size()) {
                if (mp[s[left]] == 1)
                    mp.erase(s[left]);
                else
                    --mp[s[left]];
                ++left;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};

