#pragma once
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> se;
        for (int& num : nums)
            if (se.count(num))
                return true;
            else
                se.insert(num);
        return false;
    }
};
