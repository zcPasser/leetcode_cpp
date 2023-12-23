#pragma once
#include<vector>
#include<unordered_map>
class Solution {
public:
    int leastBricks(std::vector < std::vector<int >> &wall) {
        using namespace std;
        int wallSize = wall.size();
        unordered_map<int, int> uomp;
        for (int i = 0, sum = 0; i < wallSize; ++i, sum = 0) {
            for (const int& brick : wall[i]) {
                sum += brick;
                ++uomp[sum];
            }
            uomp.erase(sum);
        }
        int ans = wallSize;
        for (auto& it : uomp)
            ans = min(ans, wallSize - it.second);
        return ans;
    }
};

