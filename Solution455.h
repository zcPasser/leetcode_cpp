#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gSize = g.size(), sSize = s.size();
        int ans = 0;
        int i = 0, j = 0;
        while (i < gSize && j < sSize) {
            if (g[i] <= s[j]) {
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};

