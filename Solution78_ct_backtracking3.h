#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void backtracking(const vector<int>& nums, int nsSize, int start, vector<int>& path, vector<vector<int>>& ans)
    {
        //if()
        for (int i = start; i < nsSize; ++i)
        {
            //visited[i] = true;
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, nsSize, i + 1, path, ans);
            path.pop_back();
            //visited[i] = false;
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int nsSize = nums.size();
        //vector<bool> visited(nsSize, false);
        vector<int> path;
        vector<vector<int>> ans;
        ans.push_back({});
        backtracking(nums, nsSize, 0, path, ans);
        return ans;
    }
};

