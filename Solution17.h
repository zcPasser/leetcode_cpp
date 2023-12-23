#pragma once
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
private:
    const string phoneNumber[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    string path;
    vector<string> ans;
    void backtracking(const string& digits, int beginIdx) {
        if (beginIdx == digits.size()) {
            ans.push_back(path);
            return;
        }
        int digit = digits[beginIdx] - '0';
        string s = phoneNumber[digit];
        for (char ch: s) {
            path.push_back(ch);
            backtracking(digits, beginIdx + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        path.clear();
        if (digits.size() == 0)
            return ans;
        backtracking(digits, 0);
        return ans;
    }
};
