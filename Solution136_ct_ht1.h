#pragma once
#include<vector>
#include<set>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        using namespace std;
        set<int> se;
        for (const int& num : nums)
            if (se.find(num) != se.end())
                se.erase(num);
            else
                se.insert(num);
        return *se.begin();
    }
};

