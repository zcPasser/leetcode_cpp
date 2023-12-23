#pragma once
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersection;
        int idx1 = 0, idx2 = 0;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        while (idx1 < nums1Size && idx2 < nums2Size) {
            if (nums1[idx1] == nums2[idx2]) {
                if (!intersection.size() || intersection.back() != nums1[idx1]) {
                    intersection.push_back(nums1[idx1]);
                }
                ++idx1, ++idx2;
            }
            else if (nums1[idx1] < nums2[idx2])
                ++idx1;
            else
                ++idx2;
        }
        return intersection;
    }
};

