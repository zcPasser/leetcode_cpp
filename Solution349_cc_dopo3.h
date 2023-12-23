#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int idx1 = 0, idx2 = 0;
        int n1Size = nums1.size(), n2Size = nums2.size();
        while (idx1 < n1Size && idx2 < n2Size)
        {
            if (nums1[idx1] == nums2[idx2])
            {
                if (ans.empty() || ans.back() != nums1[idx1])
                {
                    ans.push_back(nums1[idx1]);
                }
                idx1++, idx2++;
            }
            else if (nums1[idx1] < nums2[idx2])
                idx1++;
            else
                idx2++;
        }
        return ans;
    }
};

