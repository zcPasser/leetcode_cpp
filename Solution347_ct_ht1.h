#pragma once
#include<vector>
#include<unordered_map>
#include<queue>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        using namespace std;
        vector<int> ans;
        unordered_map<int, int> mp;
        for (const int& num : nums)
            ++mp[num];
        priority_queue<pair<int, int>> que;
        for (auto it : mp)
            que.emplace(it.second, it.first);
        while (k > 0) {
            ans.push_back(que.top().second);
            que.pop();
            --k;
        }
        return ans;
    }
};

