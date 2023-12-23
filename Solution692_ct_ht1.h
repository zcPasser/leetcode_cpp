#pragma once
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        using namespace std;
        int wordsSize = words.size();
        unordered_map<string, int>mp;
        for (const string& word : words)
            ++mp[word];
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first<b.first : a.second>b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
        for (auto& it : mp) {
            que.emplace(it);
            if (que.size() > k)
                que.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = que.top().first;
            que.pop();
        }
        return ans;
    }
};

