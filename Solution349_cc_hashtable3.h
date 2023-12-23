#pragma once
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> unse(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int val : nums2) {
            if (unse.count(val)) {
                ans.push_back(val);
                unse.erase(val);
            }                
        }
        return ans;
    }
};

