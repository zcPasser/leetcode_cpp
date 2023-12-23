#pragma once
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string& s) {
        // Write your code here
        int sSize = s.size();
        if (sSize < 3)
            return sSize;
        unordered_map<char, int> mp;
        int ans = 0;
        int left = 0, right = 0;
        while (right < sSize) {
            ++mp[s[right]];
            while (mp.size() > 2) {
                --mp[s[left]];
                if (mp[s[left]] == 0)
                    mp.erase(s[left]);
                ++left;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};

