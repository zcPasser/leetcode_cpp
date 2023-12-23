#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(const vector<int>& nums, int beginIdx) {
        ans.push_back(path);
        for (int i = beginIdx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        ans.clear();
        backtracking(nums, 0);
        return ans;
    }
};
