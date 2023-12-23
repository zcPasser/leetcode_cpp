#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<vector<bool>> isPalindrome;
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        if (sSize < 2)
            return s;
        int maxSize = 0;
        string ans;
        isPalindrome.resize(sSize, vector<bool>(sSize, false));
        for (int i = sSize - 1; i >= 0; i--) {
            for (int j = i; j < sSize; j++) {
                if (j == i)
                    isPalindrome[i][j] = true;
                else if (j - i == 1)
                    isPalindrome[i][j] = s[i] == s[j];
                else
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                if (isPalindrome[i][j] && (j - i + 1) > maxSize) {
                    maxSize = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};

