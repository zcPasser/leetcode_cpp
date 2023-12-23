#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nsSize = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // {a,b,c}
        for (int i = 0; i < nsSize - 2; i++) {
            // 剪枝
            if (nums[i] > 0)
                return ans;
            // 组间去重a
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nsSize - 1;
            int target = -nums[i];
            while (left < right) {
                if (nums[left] < target - nums[right])
                    left++;
                else if (nums[left] > target - nums[right])
                    right--;
                else {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    // 组内去重b c
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }

            }
        }
        return ans;
    }
};

