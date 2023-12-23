#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int charToInt[26] = { 0 };
        int sSize = s.size();
        vector<int> ans;
        for (int i = 0; i < sSize; i++) {
            charToInt[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        for (int i = 0; i < sSize; i++) {
            right = max(right, charToInt[s[i] - 'a']);
            if (i == right) {
                ans.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return ans;
    }
};
