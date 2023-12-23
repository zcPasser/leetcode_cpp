#pragma once
#include <vector>
#include <unordered_set>
using namespace std;
class Solution349
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int val : nums2) {
            if (nums1_set.find(val) != nums1_set.end()) {
                ans.insert(val);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

