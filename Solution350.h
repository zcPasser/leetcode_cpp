#pragma once
#include<vector>
using namespace std;
class Solution350
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int nums_map[1001] = { 0 };
        for (int num : nums1) {
            nums_map[num]++;
        }
        vector<int> ans;
        for (int num : nums2) {
            if (nums_map[num] > 0) {
                nums_map[num]--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};

