#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        using namespace std;
        unordered_map<int, int> map;
        int numsSize = nums.size();
        vector<int> ans;
        for (int i = 0; i < numsSize; ++i) {
            if (map.find(nums[i]) != map.end()) {
                ans.push_back(map[nums[i]]);
                ans.push_back(i);
                break;
            }
            else {
                map[target - nums[i]] = i;
            }
        }
        return ans;
    }
};

