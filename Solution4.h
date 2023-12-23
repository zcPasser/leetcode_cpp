#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        bool isOdd = (m + n) % 2 == 1 ? true : false;
        int mid = (m + n) / 2;
        int i = 0, j = 0;
        int idx = -1;
        vector<int> ans;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    ans.push_back(nums1[i]);
                    i++;
                }
                else {
                    ans.push_back(nums2[j]);
                    j++;
                }
            }
            else if (i < m) {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (j < n) {
                ans.push_back(nums2[j]);
                j++;
            }
            idx++;
            if (idx == mid) {
                if (isOdd)
                    return ans[idx];
                else
                    return (ans[idx] + ans[idx - 1]) / 2.0;
            }   
        }
        return 0;
    }
};
