#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtraking(vector<int>& candidates, int target, int sum, int beginIdx) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = beginIdx; i < candidates.size(); i++) {
            if ((sum + candidates[i]) > target)
                return;
            path.push_back(candidates[i]);
            backtraking(candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        ans.clear();
        sort(candidates.begin(), candidates.end());
        backtraking(candidates, target, 0, 0);
        return ans;
    }
};
