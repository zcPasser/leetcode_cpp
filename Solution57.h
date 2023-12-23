#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervalsSize = intervals.size();    
        if (intervalsSize == 0 || intervals[intervalsSize - 1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < intervalsSize; ++i) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            //无重叠
            else if (intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            }
            //有重叠
            else {
                int j = i + 1;
                while (j < intervalsSize && intervals[j][0] <= newInterval[1]) {
                    ++j;
                }
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[j - 1][1], newInterval[1]);
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + j, intervals.end());
                return ans;
            }
        }
        return ans;
    }
};

