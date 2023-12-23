#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nsSize = nums.size();
        if (nsSize < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int a = 0; a < nsSize - 3; a++) {
            // 一级剪枝
            if (nums[a] > target && nums[a] >= 0)
                break;
            // a去重
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            // 已确定 a
            for (int b = a + 1; b < nsSize - 2; b++) {
                long tmp = nums[a] + nums[b];
                // 二级剪枝
                if (tmp > target && tmp >= 0)
                    break;
                // b去重
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                
                int c = b + 1, d = nsSize - 1;
                while (c < d) {
                    if ((long)tmp + nums[c] + nums[d] < target)
                        c++;
                    else if ((long)tmp + nums[c] + nums[d] > target)
                        d--;
                    else {
                        ans.push_back({ nums[a], nums[b], nums[c], nums[d] });
                        // c去重
                        while (c < d && nums[c] == nums[c + 1])
                            c++;
                        // d去重
                        while (d > c && nums[d] == nums[d - 1])
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};

