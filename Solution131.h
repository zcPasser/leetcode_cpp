#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<string> path;
    vector<vector<string>> ans;
    vector<vector<bool>> isPalindrome;
    bool isPalindromeStr(const string& s) {
        int sSize = s.size();
        if (sSize < 2)
            return true;
        int i = 0, j = sSize - 1;
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    void computePalindromeStr(const string& s) {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) {
                    isPalindrome[i][j] = true;
                }
                else if (j - i == 1) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else {
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }
    void backtracking(const string& s, int beginIdx) {
        if (beginIdx == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int endIdx = beginIdx + 1; endIdx <= s.size(); endIdx++) {
            string ss = s.substr(beginIdx, endIdx - beginIdx);
            if (isPalindrome[beginIdx][endIdx - 1]) {
                path.push_back(ss);
                backtracking(s, endIdx);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        ans.clear();
        computePalindromeStr(s);
        backtracking(s, 0);
        return ans;
    }
};
