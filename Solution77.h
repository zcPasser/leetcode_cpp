#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(int cur, int n, int k) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = cur; i <= n; i++) {
            path.push_back(i);
            backtracking(i + 1, n, k);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        path.clear();
        backtracking(1, n, k);
        return ans;
    }
};
