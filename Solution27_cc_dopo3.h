#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nsSize = nums.size();
        int slow = 0, fast = 0;
        while (true)
        {
            while (fast < nsSize && nums[fast] == val)
                ++fast;
            if (fast >= nsSize)
                break;
            nums[slow++] = nums[fast++];
        }
        return slow;
    }
};

