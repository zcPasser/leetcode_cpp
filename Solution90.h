#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, int beginIdx) {
        ans.push_back(path);
        for (int i = beginIdx; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        path.clear();
        ans.clear();
        backtracking(nums, 0);
        return ans;
    }
};
