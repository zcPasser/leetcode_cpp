#pragma once
#include<vector>
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        vector<int> dp(nums2Size + 1, 0);
        int ans = 0;
        for (int i = 1; i <= nums1Size; ++i) {
            for (int j = nums2Size; j >= 1; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                    
                }
                else
                    dp[j] = 0;
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};
