#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nsSize = nums.size();
        if (nsSize < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int a = 0; a < nsSize - 3; a++)
        {
            // 剪枝
            if (nums[a] >= 0 && nums[a] > target)
                break;
            // 去重 a
            if (a > 0 && nums[a] == nums[a - 1])
                continue;

            for (int b = a + 1; b < nsSize - 2; b++)
            {
                long long currVal = nums[a] + nums[b];
                // 剪枝
                if (currVal >= 0 && currVal > target)
                    break;
                // 去重 b
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                int c = b + 1, d = nsSize - 1;
                while (c < d)
                {
                    if ((long long)nums[c] + nums[d] + currVal == target)
                    {
                        ans.push_back({ nums[a], nums[b], nums[c], nums[d] });
                        while (c < d - 1 && nums[c] == nums[c + 1])
                            c++;
                        while (c + 1 < d && nums[d] == nums[d - 1])
                            d--;
                        c++, d--;
                    }
                    else if ((long long)nums[c] + nums[d] + currVal > target)
                        d--;
                    else
                        c++;
                }

            }

        }
        return ans;
    }
};
