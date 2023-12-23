#pragma once
#include<string>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
private:
    vector<string> path;
    vector<string> ans;
    bool isLegal(const string& s, int beginIdx, int endIdx) {
        if (beginIdx > endIdx)
            return false;
        if (s[beginIdx] == '0' && beginIdx != endIdx)
            return false;
        int val = 0;
        for (int i = beginIdx; i <= endIdx; i++) {
            if (s[i] < '0' || s[i]>'9')
                return false;
            val = val * 10 + (s[i] - '0');
            if (val > 255)
                return false;
        }
        return true;
    }
    void backtracking(const string& s, int beginIdx) {
        if (path.size() == 3) {
            string ss = s.substr(beginIdx, s.size() - beginIdx);
            if (isLegal(ss, 0, ss.size() - 1)) {
                path.push_back(ss);
                ans.push_back(accumulate(path.begin(), path.end(), string{},
                    [](const string& a, const string& b)->string {return a.empty() ? b : a + "." + b; })
                );
                path.pop_back();
            }
            return;
        }
        for (int i = beginIdx; i < s.size(); i++) {
            string ss = s.substr(beginIdx, i - beginIdx + 1);
            if (isLegal(ss, 0, ss.size() - 1)) {
                path.push_back(ss);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        ans.clear();
        if (s.size() < 4 || s.size() > 12) return ans; // À„ «ºÙ÷¶¡À
        backtracking(s, 0);
        return ans;
    }
};

