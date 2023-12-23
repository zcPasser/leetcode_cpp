#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    pair<int, int> centerSpread(const string& s, int size, int left, int right) {
        while (left >= 0 && right < size) {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else
                break;
        }
        return { left + 1,right - left - 1 };
    }
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        if (sSize < 2)
            return s;
        pair<int, int> ans={0,0};
        for (int i = 0; i < sSize; ++i) {
            pair<int, int> odd = centerSpread(s, sSize, i, i);
            pair<int, int> even = centerSpread(s, sSize, i, i + 1);
            pair<int, int>& cur = odd.second > even.second ? odd : even;
            if (ans.second < cur.second) {
                ans.first = cur.first;
                ans.second = cur.second;
            }
        }
        return s.substr(ans.first, ans.second);
    }
};

