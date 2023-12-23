#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int>path;
    vector<bool> used;
    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
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
        int nsSize = nums.size();
        ans.clear();
        path.clear();
        used.resize(nsSize, false);
        backtracking(nums);
        return ans;
    }
};

