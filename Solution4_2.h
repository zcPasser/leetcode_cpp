#pragma once
#include<vector>
#include<limits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            std::swap(nums1, nums2);
            std::swap(m, n);
        }
        // 节省不必要的内存分配
        nums1.resize(m);
        nums1.shrink_to_fit();

        int lMax1, rMin1, lMax2, rMin2, c1, c2, lo = 0, hi = m * 2;
        while (lo <= hi) {
            c1 = lo + (hi - lo) / 2;
            c2 = m + n - c1;

            lMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            rMin1 = (c1 == 2 * m) ? INT_MAX : nums1[c1 / 2];
            lMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            rMin2 = (c2 == 2 * n) ? INT_MAX : nums2[c2 / 2];

            if (lMax1 > rMin2)
                hi = c1 - 1;
            else if (lMax2 > rMin1)
                lo = c1 + 1;
            else 
                break;
        }
        return (max(lMax1, lMax2) + min(rMin1, rMin2)) / 2.0;
    }
};

