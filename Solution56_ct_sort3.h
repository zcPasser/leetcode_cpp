#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        int idx = 0;
        int intvalsSize = intervals.size();
        for (int i = 1; i < intvalsSize; i++) {
            if (ans[idx][1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
                idx++;
            }
            else if (ans[idx][1] > intervals[i][1])
                continue;
            else {
                ans[idx][1] = intervals[i][1];
                continue;
            }
        }
        return ans;
    }
};

