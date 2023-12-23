#pragma once
#include<vector>
class Solution {
private:
    int maxLength(const std::vector<int>& nums1, const std::vector<int>& nums2, int beginIdx1, int beginIdx2, int size) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (nums1[beginIdx1 + i] == nums2[beginIdx2 + i])
                cnt++;
            else
                cnt = 0;
            ans = std::max(ans, cnt);
        }
        return ans;
    }
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        
        int ans = 0, tmpLen = 0, size = 0;
        
        for (int i = 0; i < nums1Size; ++i) {
            size = min(nums2Size, nums1Size - i);
            if (size <= ans)
                break;
            tmpLen = maxLength(nums1, nums2, i, 0, size);
            ans = max(ans, tmpLen);
        }
        for (int i = 0; i < nums2Size; ++i) {
            size = min(nums1Size, nums2Size - i);
            if (size <= ans)
                break;
            tmpLen = maxLength(nums1, nums2, 0, i, size);
            ans = max(ans, tmpLen);
        }

        return ans;
    }
};

