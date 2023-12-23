#pragma once
#include<vector>
#include<unordered_map>
#include<string>
class Solution {
private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        using namespace std;
        int pSize = points.size();
        if (pSize < 3)
            return pSize;
        int ans = 1;
        string key;
        for (int i = 0; i < pSize; ++i) {
            if (ans >= pSize - i || ans > pSize / 2)
                break;
            unordered_map<string, int>mp;
            int curMax = 0;
            for (int j = i + 1; j < pSize; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int k = gcd(dx, dy);
                key = to_string(dx / k) + "_" + to_string(dy / k);
                ++mp[key];
                curMax = max(curMax, mp[key]);
            }
            ans = max(ans, curMax + 1);
        }
        return ans;
    }
};
