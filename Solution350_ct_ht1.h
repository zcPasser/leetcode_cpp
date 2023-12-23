#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnts(1001, 0);
        for (int& num : nums1)
            cnts[num]++;
        vector<int> ans;
        for (int& num : nums2) {
            if (cnts[num] > 0) {
                ans.push_back(num);
                cnts[num]--;
            }
        }
        return ans;
    }
};

