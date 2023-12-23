#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        else if (m == 0)
        {
            int idx = n - 1, j = n - 1;
            while (j >= 0)
                nums1[idx--] = nums2[j--];
            return;
        }
        else
        {
            int idx = m + n - 1, i = m - 1, j = n - 1;
            while (idx >= 0 && i >= 0 && j >= 0)
            {
                if (nums1[i] < nums2[j])
                    nums1[idx] = nums2[j--];
                else
                    nums1[idx] = nums1[i--];
                idx--;
            }
            while (i >= 0)
                nums1[idx--] = nums1[i--];
            while (j >= 0)
                nums1[idx--] = nums2[j--];
        }

        return;
    }
};

