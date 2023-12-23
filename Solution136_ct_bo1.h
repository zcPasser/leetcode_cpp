#pragma once
#include<vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        using namespace std;
        int ans = 0;
        for (const int& num : nums)
            ans ^= num;
        return ans;
    }
};

