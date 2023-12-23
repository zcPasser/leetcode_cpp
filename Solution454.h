#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Solution454
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> buffer;
        int ans = 0;
        for(int a: nums1)
            for (int b : nums2) {
                buffer[a + b]++;
            }
        for(int c:nums3)
            for (int d : nums4) {
                if (buffer.find(-c - d) != buffer.end()) {
                    ans += buffer[-c - d];
                }
            }
        return ans;
    }
};

