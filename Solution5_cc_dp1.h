#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        vector<vector<bool>> isPalindrome(sSize, vector<bool>(sSize, false));
        string ans;
        int maxSize = 0;
        int begin = 0;
        for (int i = sSize - 1; i >= 0; --i) {
            for (int j = i; j < sSize; ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        isPalindrome[i][j] = true;
                    else
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
                if (isPalindrome[i][j] && (j - i + 1) > maxSize) {
                    maxSize = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxSize);
    }
};

