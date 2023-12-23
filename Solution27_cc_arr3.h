#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nsSize = nums.size();
        int slow = 0, fast = 0;
        while (fast < nsSize) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};
