#pragma once
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<string> ans;
    unordered_map<string, map<string, int>> used;
    bool backtracking(int ticketNums) {
        if (ans.size() == (ticketNums + 1)) {
            return true;
        }
        for (pair<const string, int>& u : used[ans.back()]) {
            if (u.second > 0) {
                ans.push_back(u.first);
                u.second--;
                if (backtracking(ticketNums))
                    return true;
                ans.pop_back();
                u.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();
        used.clear();
        for (const auto& ticket : tickets) {
            used[ticket[0]][ticket[1]]++;
        }
        ans.push_back("JFK");
        backtracking(tickets.size());
        return ans;

    }
};

