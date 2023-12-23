#pragma once
#include<vector>
#include<set>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;

    void backtracking(const vector<int>& nums, int beginIdx) {
        if (path.size() >= 2)
            ans.push_back(path);
        //set<int> used;
        int used[201] = { 0 };
        for (int i = beginIdx; i < nums.size(); i++) {
            // 根据条件 剪枝
            if ((!path.empty() && nums[i] < path.back()) || (used[nums[i] + 100] == 1))
                continue;
            path.push_back(nums[i]);
            //used.insert(nums[i]);
            used[nums[i] + 100] = 1;
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        ans.clear();
        backtracking(nums, 0);
        return ans;
    }
};

