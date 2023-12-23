#pragma once
#include<string>
#include<vector>
class Solution {
private:
    int extend(const std::string& s, int i, int j, int size) {
        int ans = 0;
        while (i >= 0 && j < size && s[i] == s[j]) {
            --i, ++j;
            ++ans;
        }
        return ans;
    }
public:
    int countSubstrings(std::string s) {
        using namespace std;
        int sSize = s.size();
        int ans = 0;
        for (int i = 0; i < sSize; ++i) {
            ans += extend(s, i, i, sSize);
            ans += extend(s, i, i + 1, sSize);
        }
        return ans;
    }
};


