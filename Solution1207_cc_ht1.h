#pragma once
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int arrSize = arr.size();
        if (arrSize < 2)
            return true;
        unordered_map<int, int>mp;
        for (const int& num : arr)
            ++mp[num];
        unordered_set<int> se;
        for (const auto it : mp) {
            if (se.count(it.second))
                return false;
            se.insert(it.second);
        }
        return true;
    }
};

