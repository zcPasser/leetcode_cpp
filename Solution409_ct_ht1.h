#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        int ans = 0;
        for (char ch : s)
            ++cnt[ch];
        for (int i = 0; i < 128; ++i)
            ans += cnt[i] / 2 * 2;
        if (ans < s.size())
            ++ans;
        return ans;
    }
};
