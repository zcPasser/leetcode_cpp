#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int beginIdx, int sum, int k, int n) {
        if (path.size() == k) {
            if (sum == n) {
                ans.push_back(path);
            }
            return;
        }
        for (int i = beginIdx; i <= 9 - (k - path.size()) + 1; i++) {
            if (sum + i > n) {
                return;
            }
            path.push_back(i);
            backtracking(i + 1, sum + i, k, n);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        ans.clear();
        backtracking(1, 0, k, n);
        return ans;
    }
};

