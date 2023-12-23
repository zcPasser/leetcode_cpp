#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int intervalsSize = intervals.size();
        if (intervalsSize < 2)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervalsSize; i++) {
            if (end <= intervals[i][0]) {
                cnt++;
                end = intervals[i][1];
            }
        }
        return intervalsSize - cnt;
    }
};

