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
    int findMinArrowShots(vector<vector<int>>& points) {
        int pointsSize = points.size();
        if (pointsSize == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int ans = 1;
        for (int i = 1; i < pointsSize; i++) {
            if (points[i - 1][1] < points[i][0])
                ans++;
            else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return ans;
    }
};

