#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingsSize = ratings.size();
        if (ratingsSize < 2)
            return ratingsSize;
        vector<int> candys(ratingsSize, 1);
        for (int i = 1; i < ratingsSize; i++) {
            if (ratings[i] > ratings[i - 1])
                candys[i] = candys[i - 1] + 1;
        }
        int ans = candys[ratingsSize - 1];
        for (int i = ratingsSize - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
            ans += candys[i];
        }
        
        return ans;
    }
};

