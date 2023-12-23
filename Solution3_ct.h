#pragma once
#include<string>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        using namespace std;
        unordered_map<char, int> map;
        int sSize = s.size();
        if (sSize < 2)
            return sSize;
        int left = 0, right = 0;
        int ans = 0;
        while (right < sSize) {
            ++map[s[right]];
            while ((right - left + 1) > map.size()) {
                map[s[left]]--;
                if (map[s[left]] == 0)
                    map.erase(s[left]);
                ++left;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};

