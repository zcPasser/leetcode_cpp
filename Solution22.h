#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    string path;
    vector<string> ans;
    void backtracking(int n, char chDict[], int cnt[]) {
        if (path.size() == n * 2) {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < 2; i++) {
            if ((cnt[i] >= n) || (i == 1 && cnt[0] <= cnt[1])) {
                continue;
            }
            path += chDict[i];
            cnt[i] += 1;
            backtracking(n, chDict, cnt);
            path.pop_back();
            cnt[i] -= 1;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        if (n == 1)
            ans.push_back("()");
        else if (n > 1) {
            path += '(';
            char chDict[] = { '(', ')' };
            int cnt[] = { 1, 0 };
            backtracking(n, chDict, cnt);
        }
        return ans;
    }
};

