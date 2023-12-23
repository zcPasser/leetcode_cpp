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
        int intervalsSize = intervals.size();
        if (intervalsSize < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int idx = 0;
        for (int i = 1; i < intervalsSize; i++) {
            if (ans[idx][1] >= intervals[i][0]) {
                if (ans[idx][1] < intervals[i][1])
                    ans[idx][1] = intervals[i][1];
            }
            else {
                ans.push_back(intervals[i]);
                idx++;
            }
        }
        return ans;
    }
};

