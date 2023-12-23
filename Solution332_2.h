#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;
    void dfs(const string& cur) {
        while (vec.count(cur) && vec[cur].size() > 0) {
            string tmp = vec[cur].top();
            vec[cur].pop();
            dfs(move(tmp));
        }
        stk.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            vec[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }
};
