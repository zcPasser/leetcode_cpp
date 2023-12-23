#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costSize = cost.size();
        //int ans = 0;
        int preDp1 = 0, preDp2 = 0;
        int cur = 0;
        for (int i = 2; i < costSize; i++) {
            cur = min(preDp1 + cost[i - 2], preDp2 + cost[i - 1]);
            preDp1 = preDp2;
            preDp2 = cur;
        }
        return min(preDp1 + cost[costSize - 2], preDp2 + cost[costSize - 1]);
    }
};

