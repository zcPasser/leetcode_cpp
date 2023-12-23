#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int sSize = s.size();
        if (sSize < 2)
            return 0;
        vector<vector<bool>> isPalindromic(sSize, vector<bool>(sSize, false));
        for (int i = sSize - 1; i >= 0; --i) {
            for (int j = i; j < sSize; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1]))
                    isPalindromic[i][j] = true;
            }
        }
        vector<int> minCut(sSize, sSize);
        for (int i = 0; i < sSize; ++i)
            minCut[i] = i;
        for (int i = 1; i < sSize; ++i) {
            if (isPalindromic[0][i]) {
                minCut[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j)
                if (isPalindromic[j + 1][i])
                    minCut[i] = min(minCut[j] + 1, minCut[i]);
        }
        return minCut[sSize - 1];
    }
};
