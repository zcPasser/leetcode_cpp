#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        using namespace std;
        int ans = 0, pre = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (const int& num : nums) {
            pre += num;
            if (map.find(pre - k) != map.end())
                ans += map[pre - k];
            ++map[pre];
        }

        return ans;
    }
};

