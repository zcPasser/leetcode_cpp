#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
class Solution1
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> buffer;
        int len_nums = nums.size();
        for (int i = 0; i < len_nums; i++) {
            if (buffer.find(target - nums[i]) != buffer.end()) {
                ans.push_back(i);
                ans.push_back(buffer[target - nums[i]]);
                break;
            }
            else {
                buffer[nums[i]] = i;
            }
        }
        return ans;
    }
};

