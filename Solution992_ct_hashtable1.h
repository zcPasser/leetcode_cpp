#pragma once
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
private:
    int atMostKDistinct(const vector<int>& nums, int k) {
        int numsSize = nums.size();
        if (numsSize < k)
            return 0;
        vector<int> freq(numsSize + 1, 0);
        int left = 0, right = 0;
        //[left, right)里不同整数的个数
        int cnt = 0;
        int ans = 0;
        //[left, right)包含不同整数的个数 <= k
        while (right < numsSize) {
            if (freq[nums[right]] == 0)
                ++cnt;
            ++freq[nums[right]];
            right++;

            while (cnt > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    cnt--;
                left++;
            }
            ans += right - left;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};

