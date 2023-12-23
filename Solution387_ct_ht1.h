#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int sSize = s.size();
        vector<pair<int, int>> cnt(26, make_pair(0, sSize));
        for (int i = 0; i < sSize; ++i) {
            ++cnt[s[i] - 'a'].first;
            if (cnt[s[i] - 'a'].first == 1)
                cnt[s[i] - 'a'].second = i;
        }
        int ans = sSize;
        for (int i = 0; i < 26; ++i)
            if (cnt[i].first == 1)
                ans = min(ans, cnt[i].second);
        return ans == sSize ? -1 : ans;
    }
};

