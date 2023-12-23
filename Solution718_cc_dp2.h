#pragma once
#include<vector>
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int ans = 0;
        vector<int> dp(nums2Size + 1, 0);

        for (int i = 0; i < nums1Size; ++i) {
            //dp[0] = (nums1[i] == nums2[0]) ? 1 : 0;
            for (int j = nums2Size - 1; j >= 0; --j) {
                if (nums1[i] == nums2[j])
                    dp[j + 1] = dp[j] + 1;
                else
                    dp[j + 1] = 0;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans;
    }
};


