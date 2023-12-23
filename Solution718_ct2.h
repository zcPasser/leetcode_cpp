#pragma once
#include<vector>
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        vector<vector<int>> dp(nums1Size + 1, vector<int>(nums2Size + 1, 0));
        int ans = 0;
        for (int i = 1; i <= nums1Size; ++i) {
            for (int j = 1; j <= nums2Size; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                    
            }
        }
        return ans;
    }
};


