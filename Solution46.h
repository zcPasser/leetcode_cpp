#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(const vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        ans.clear();
        used.resize(nums.size(), false);
        backtracking(nums);
        return ans;
    }
};

