#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize < 2)
            return 0;
        int ans = 0;
        unordered_map<int, int> cnt;
        for (const int& num : nums)
            cnt[num]++;
        for (const auto& it : cnt) {
            if (cnt.count(it.first + 1))
                ans = max(ans, it.second + cnt[it.first + 1]);
            //else if(cnt.count(it.first - 1))
            //    ans = max(ans, it.second + cnt[it.first - 1]);
        }
        return ans;
    }
};

