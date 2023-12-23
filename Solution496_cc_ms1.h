#pragma once
#include<vector>
#include<stack>
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        if (nums1Size > nums2Size)
            return {};
        vector<int> ans(nums1Size, -1);
        if (nums1Size == 0)
            return ans;
        int mp[10001] = { 0 };
        stack<int> stk;
        for (int i = 0; i < nums2Size; ++i) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                mp[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1Size; ++i) {
            ans[i] = nums1[i] < mp[nums1[i]] ? mp[nums1[i]] : -1;
        }

        return ans;
    }
};
