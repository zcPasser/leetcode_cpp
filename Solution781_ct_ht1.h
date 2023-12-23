#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0)
            return 0;
        unordered_map<int, int>uomp;
        for (int& val : answers)
            ++uomp[val];
        int ans = 0;
        for (auto& it : uomp) {
            ans += it.second / (it.first + 1) * (it.first + 1);
            if (it.second % (it.first + 1) != 0)
                ans += (it.first + 1);
        }
        return ans;
    }
};

