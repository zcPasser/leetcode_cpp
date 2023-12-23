#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        using namespace std;
        int numsSize = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> mp = { {0,1} };
        int modulus = 0;
        for (const int& num : nums) {
            sum += num;
            modulus = (sum % k + k) % k; 
            ++mp[modulus];
        }
        for (const auto& item : mp)
            ans += item.second * (item.second - 1) / 2;
        return ans;
    }
};

