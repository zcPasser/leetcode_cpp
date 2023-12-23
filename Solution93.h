#pragma once
#include<string>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
private:
    vector<string> path;
    vector<string> ans;
    bool isLegalIPStr(const string& s) {
        int val = stoi(s);
        return 0 <= val && val <= 255;
    }
    void backtracking(const string& s, int beginIdx) {
        if (path.size() == 4) {
            if (beginIdx < s.size())
                return;
            ans.push_back(
                accumulate(path.cbegin(), path.cend(), std::string{},
                    [](const std::string& a, const std::string& b) -> std::string {
                        return a.empty() ? b : a + "." + b;
                    }
                )
            );
            return;
        }
        if (s[beginIdx] == '0') {
            path.push_back("0");
            backtracking(s, beginIdx + 1);
            path.pop_back();
        }
        else {
            for (int endIdx = beginIdx; endIdx < beginIdx + 3 && endIdx < s.size(); endIdx++) {
                string ipStr = s.substr(beginIdx, endIdx - beginIdx + 1);
                if (isLegalIPStr(ipStr)) {
                    path.push_back(ipStr);
                    backtracking(s, endIdx + 1);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        ans.clear();
        backtracking(s, 0);
        return ans;
    }
};
