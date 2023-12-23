#pragma once
#include<vector>
#include<unordered_set>
class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        using namespace std;
        unordered_set<int> uose;
        for (const int& num : nums) {
            if (uose.find(num) != uose.end())
                return num;
            uose.insert(num);
        }
        return -1;
    }
};

