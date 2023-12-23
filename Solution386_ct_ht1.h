#pragma once
#include<string>
#include<unordered_map>
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(std::string& s, int k) {
        // write your code here
        using namespace std;
        int sSize = s.size();
        if (sSize == 0)
            return 0;
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int ans = 0;
        while (right < sSize) {
            ++mp[s[right]];
            while (mp.size() > k) {
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

