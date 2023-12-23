#pragma once
#include<vector>
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int ans = 1;
        vector<vector<int>> dp(nums1Size, vector<int>(nums2Size, 0));
        for (int i = 0; i < nums2Size; ++i) {
            dp[0][i] = (nums1[0] == nums2[i]) ? 1 : 0;
            if (ans == 0 && dp[0][i] == 1)
                ans = 1;
        }
            
        for (int i = 0; i < nums1Size; ++i) {
            dp[i][0] = (nums1[i] == nums2[0]) ? 1 : 0;
            if (ans == 0 && dp[i][0] == 1)
                ans = 1;
        }
            
        for (int i = 1; i < nums1Size; ++i) {
            for (int j = 1; j < nums2Size; ++j) {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

