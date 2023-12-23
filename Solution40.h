#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates, int target, int sum, int beginIdx, vector<int>& used) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = beginIdx; i < candidates.size(); i++) {
            if ((candidates[i] + sum) > target)
                return;
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum + candidates[i], i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> used(candidates.size(), false);
        backtracking(candidates, target, 0, 0, used);
        return ans;
    }
};

