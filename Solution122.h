#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        if (pricesSize < 2)
            return 0;
        int ans = 0;
        int preOrder = 0, preOrderEnd = prices[0];
        int curOrder = 0, curOrderEnd = prices[0];
        for (int i = 1; i < pricesSize; i++) {
            curOrder = prices[i] - prices[i - 1];
            if (curOrder > 0) {
                ans += curOrder;
            }
        }
        return ans;
    }
};

